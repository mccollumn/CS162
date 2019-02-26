/*
@Filename:		game.cpp
@Author:		Nick McCollum
@Date:			2/24/2019
@Version:		2.0
@Dev env:		VS 2017
@Description:	Main game class.
*/

#include "game.h"

Game::Game() {
	gameWell = nullptr;
	tetriminoInPlay = nullptr;
	tetriminoNext = nullptr;
	score = 0;
	level = 1;
	currentDropRate = TETRIMINO_DROP_RATE;
	currentMusicPitch = 1.0;

	// Font
	if (!font.loadFromFile("ZCOOLQingKeHuangYou-Regular.ttf")) {
		printError("ZCOOLQingKeHuangYou-Regular.ttf");
	}

	// Background image
	if (!backgroundImage.loadFromFile("background.jpg")) {
		printError("background.jpg");
	}
	background.setTexture(backgroundImage);
	background.setColor(sf::Color(255, 255, 255, 128));

	// Music
	if (!music.openFromFile("tetris.ogg")) {
		printError("tetris.oog");
	}
	music.setVolume(10.f);
	music.setLoop(true);

	// Tetrimino block
	tetriminoBlock.setSize(sf::Vector2f(BLOCK_SIZE_PIXELS, BLOCK_SIZE_PIXELS));
	tetriminoBlock.setOutlineColor(sf::Color(50, 50, 50));

	// Game window
	window.create(
		sf::VideoMode(LAYOUT_WINDOW_WIDTH, LAYOUT_WINDOW_HEIGHT),
		"Tetris 2019",
		sf::Style::Titlebar | sf::Style::Close);
}

Game::~Game() {
	if (tetriminoInPlay) {
		delete tetriminoInPlay;
	}
	if (tetriminoNext) {
		delete tetriminoNext;
	}
	if (gameWell) {
		delete gameWell;
	}
}

sf::Color Game::convertToSfmlColor(char color) {
	switch (color) {
	case 't':
		return sf::Color::Cyan;
	case 'b':
		return sf::Color::Blue;
	case 'o':
		return sf::Color::Magenta;
	case 'y':
		return sf::Color::Yellow;
	case 'g':
		return sf::Color::Green;
	case 'p':
		return sf::Color::Black;
	case 'r':
		return sf::Color::Red;
	default:
		return sf::Color::Transparent;
	}
}

void Game::printError(std::string filename) {
	std::cout << "Error: Cannot load " << filename << std::endl;
}

Location Game::getTetriminoCenter(Tetrimino* tetrimino, int blockWidth) {
	int type = tetrimino->getType();
	Location center = {};

	if (type == 0) {
		center.row = 1.5 * blockWidth;
		center.col = 2 * blockWidth;
		return center;
	}
	else {
		center.row = 2 * blockWidth;
	}
	if (type == 3) {
		center.col = 2 * blockWidth;
	}
	else {
		center.col = 2.5 * blockWidth;
	}
	return center;
}

Dimensions Game::getTetriminoDimensions(Tetrimino* tetrimino, int blockWidth) {
	int grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	tetrimino->getGrid(grid);
	Dimensions tetriminoSize = {};
	int rowTop = 0;
	int rowBottom = 0;
	int colLeft = 0;
	int colRight = 0;

	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			if (grid[row][col] == 1) {
				if (row < rowTop) {
					rowTop = row;
				}
				if (row > rowBottom) {
					rowBottom = row;
				}
				if (col < colLeft) {
					colLeft = col;
				}
				if (col > colRight) {
					colRight = col;
				}
			}
		}
	}
	tetriminoSize.width = (colRight - colLeft) * blockWidth;
	tetriminoSize.height = (rowBottom - rowTop) * blockWidth;
	return tetriminoSize;
}

void Game::updateLevel(int rowsCleared) {
	static int previousRowTotal = 0;
	static int previousLevel = level;
	int totalRows = previousRowTotal + rowsCleared;
	level = (totalRows / ROWS_PER_LEVEL) + 1;
	int levelIncrease = level - previousLevel;
	if (levelIncrease > 0) {
		for (int x = 0; x < levelIncrease; x++) {
			currentDropRate -= currentDropRate * DROP_RATE_PER_LEVEL;
			currentMusicPitch += currentMusicPitch * MUSIC_RATE_PER_LEVEL;
		}
		music.setPitch(currentMusicPitch);
	}
	previousRowTotal = totalRows;
	previousLevel = level;
}

void Game::processSplash() {

	// Title
	sf::Text title;
	title.setFont(font);
	title.setString("Tetris");
	title.setCharacterSize(150);
	title.setFillColor(sf::Color::Black);
	sf::FloatRect titleRect = title.getLocalBounds();
	title.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
	title.setPosition(sf::Vector2f(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 6.0f));
	
	// Instructions
	std::string instructionText = "Controls:\nLeft Arrow - Move Piece Left\nRight Arrow - Move Piece Right\nUp Arrow - Rotate Piece\nDown Arrow - Drop Piece\n\nESC - Quite Game\nM - Toggle Music\nP - Pause Game";
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setString(instructionText);
	instructions.setCharacterSize(25);
	instructions.setFillColor(sf::Color::Black);
	sf::FloatRect instructionsRect = instructions.getLocalBounds();
	instructions.setOrigin(instructionsRect.left + instructionsRect.width / 2.0f, instructionsRect.top + instructionsRect.height / 2.0f);
	instructions.setPosition(sf::Vector2f(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 1.8f));
	
	// Start message
	sf::Text start;
	start.setFont(font);
	start.setString("Press any key to Start");
	start.setCharacterSize(50);
	start.setFillColor(sf::Color::Black);
	sf::FloatRect startRect = start.getLocalBounds();
	start.setOrigin(startRect.left + startRect.width / 2.0f, startRect.top + startRect.height / 2.0f);
	start.setPosition(sf::Vector2f(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 1.1f));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				return;
			}
		}
		window.clear(sf::Color::White);
		window.draw(background);
		window.draw(title);
		window.draw(instructions);
		window.draw(start);
		window.display();
	}
}

void Game::processGame() {

	// Click sound
	sf::SoundBuffer bufferClick;
	if (!bufferClick.loadFromFile("click.wav")) {
		printError("click.wav");
	}
	sf::Sound soundClick;
	soundClick.setBuffer(bufferClick);

	// Click sound
	sf::SoundBuffer bufferClear;
	if (!bufferClear.loadFromFile("clear.wav")) {
		printError("clear.wav");
	}
	sf::Sound soundClear;
	soundClear.setBuffer(bufferClear);

	// Error sound
	sf::SoundBuffer bufferError;
	if (!bufferError.loadFromFile("error.wav")) {
		printError("error.wav");
	}
	sf::Sound soundError;
	soundError.setBuffer(bufferError);
	soundError.setVolume(50.f);

	// Well block
	sf::RectangleShape wellBlock;
	wellBlock.setSize(sf::Vector2f(BLOCK_SIZE_PIXELS, BLOCK_SIZE_PIXELS));
	wellBlock.setOutlineThickness(-1);

	// Well graphic
	sf::RectangleShape well;
	well.setSize(sf::Vector2f(WELL_WIDTH * BLOCK_SIZE_PIXELS, WELL_HEIGHT * BLOCK_SIZE_PIXELS));
	well.setOutlineColor(sf::Color::Black);
	well.setOutlineThickness(1);
	well.setFillColor(sf::Color::Transparent);

	// Tetriminos
	tetriminoInPlay = new Tetrimino;
	tetriminoInPlay->setLocation(TETRIMINO_START_LOCATION);
	tetriminoNext = new Tetrimino;

	//Game Well
	gameWell = new Well;

	int moveCounter = 0;
	bool paused = false;

	music.play();

	while (window.isOpen() && !gameWell->topReached()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				return;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
				tetriminoInPlay->moveLeft();
				if (!gameWell->tetriminoFit(*tetriminoInPlay)) {
					tetriminoInPlay->moveRight();
					soundError.play();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
				tetriminoInPlay->moveRight();
				if (!gameWell->tetriminoFit(*tetriminoInPlay)) {
					tetriminoInPlay->moveLeft();
					soundError.play();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
				tetriminoInPlay->rotateRight();
				if (!gameWell->tetriminoFit(*tetriminoInPlay)) {
					tetriminoInPlay->rotateLeft();
					soundError.play();
				}
				soundClick.play();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
				tetriminoInPlay->moveDown();
				if (!gameWell->tetriminoFit(*tetriminoInPlay)) {
					tetriminoInPlay->moveUp();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
				int status = music.getStatus();
				if (status == 2) {
					music.stop();
				}
				if (status == 0 || status == 1) {
					music.play();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
				if (!paused) {
					paused = true;
				}
				else if (paused) {
					paused = false;
				}
			}
		}

		moveCounter++;
		if (moveCounter >= currentDropRate && !paused) {
			tetriminoInPlay->moveDown();
			if (!gameWell->tetriminoFit(*tetriminoInPlay)) {
				tetriminoInPlay->moveUp();
				gameWell->addTetriminoToWell(*tetriminoInPlay);
				delete tetriminoInPlay;
				int rowsCleared = gameWell->clearFullRows();
				if (rowsCleared == 4) {
					soundClear.play();
					score += rowsCleared * TETRIS_MULTIPLIER;
				}
				else if (rowsCleared > 0) {
					soundClear.play();
					score += rowsCleared;
				}
				if (!gameWell->topReached()) {
					updateLevel(rowsCleared);
					tetriminoInPlay = tetriminoNext;
					tetriminoInPlay->setLocation(TETRIMINO_START_LOCATION);
					tetriminoNext = new Tetrimino;
				}
			}
			moveCounter = 0;
		}

		window.clear(sf::Color::White);
		window.draw(background);
		drawNext(tetriminoNext, LAYOUT_NEXT_TOP, LAYOUT_NEXT_LEFT);
		drawWell(gameWell, LAYOUT_BOARD_TOP, LAYOUT_BOARD_LEFT, BLOCK_SIZE_PIXELS, wellBlock, well);
		drawTetrimino(tetriminoInPlay, LAYOUT_BOARD_TOP, LAYOUT_BOARD_LEFT, BLOCK_SIZE_PIXELS, tetriminoBlock);
		drawScore(score, LAYOUT_SCORE_TOP, LAYOUT_SCORE_LEFT);
		if (paused) {
			drawPause();
		}
		window.display();
	}
}

bool Game::processGameOver() {

	// Thanks
	sf::Text thanks;
	thanks.setFont(font);
	thanks.setString("Thanks for Playing");
	thanks.setCharacterSize(50);
	thanks.setFillColor(sf::Color::Black);
	sf::FloatRect thanksRect = thanks.getLocalBounds();
	thanks.setOrigin(thanksRect.left + thanksRect.width / 2.0f, thanksRect.top + thanksRect.height / 2.0f);
	thanks.setPosition(sf::Vector2f(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 6.0f));

	// Try Again
	sf::Text playAgain;
	playAgain.setFont(font);
	playAgain.setString("Press Any Key to Try Again\n");
	playAgain.setCharacterSize(25);
	playAgain.setFillColor(sf::Color::Black);
	sf::FloatRect playAgainRect = playAgain.getLocalBounds();
	playAgain.setOrigin(playAgainRect.left + playAgainRect.width / 2.0f, playAgainRect.top + playAgainRect.height / 2.0f);
	playAgain.setPosition(sf::Vector2f(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 1.25f));

	// Quit
	sf::Text quit;
	quit.setFont(font);
	quit.setString("Press ESC to Quit");
	quit.setCharacterSize(25);
	quit.setFillColor(sf::Color::Black);
	sf::FloatRect quitRect = quit.getLocalBounds();
	quit.setOrigin(quitRect.left + quitRect.width / 2.0f, quitRect.top + quitRect.height / 2.0f);
	quit.setPosition(sf::Vector2f(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 1.20f));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				return true;
			}
		}
		window.clear(sf::Color::White);
		window.draw(background);
		window.draw(thanks);
		drawScore(score, 150, 150);
		window.draw(playAgain);
		window.draw(quit);
		window.display();
	}
	return false;
}

void Game::drawWell(Well* gameWell, int top, int left, int blockWidth, sf::RectangleShape& block, sf::RectangleShape& well) {
	char gameBoard[WELL_HEIGHT][WELL_WIDTH];
	gameWell->getBoard(gameBoard);
	int currentX = left;
	int currentY = top;

	for (int row = 0; row < WELL_HEIGHT; row++) {
		for (int col = 0; col < WELL_WIDTH; col++) {
			block.setPosition(currentX, currentY);
			block.setFillColor(sf::Color(240,240,240));
			block.setOutlineColor(sf::Color::White);
			if (gameBoard[row][col] != ' ') {
				block.setFillColor(convertToSfmlColor(gameBoard[row][col]));
				block.setOutlineColor(sf::Color::Black);
			}
			else if (col % 2 == 0) {
				block.setFillColor(sf::Color(230, 230, 230));
				block.setOutlineColor(sf::Color::White);
			}
			window.draw(block);
			currentX += blockWidth;
		}
		currentX = left;
		currentY += blockWidth;
	}
	well.setPosition(left, top);
	window.draw(well);
}

void Game::drawTetrimino(Tetrimino* tetrimino, int top, int left, int blockWidth, sf::RectangleShape& block) {
	int grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	tetrimino->getGrid(grid);
	Location currentLocation = tetrimino->getLocation();
	int currentX = left + (currentLocation.col * blockWidth);
	int currentY = top + (currentLocation.row * blockWidth);
	char color = tetrimino->getColor();

	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			block.setPosition(currentX, currentY);
			if (grid[row][col] == 1 && currentY >= 0) {
				block.setFillColor(convertToSfmlColor(color));
				block.setOutlineThickness(-1);
			}
			else {
				block.setFillColor(sf::Color::Transparent);
				block.setOutlineThickness(0);
			}
			window.draw(block);
			currentX += blockWidth;
		}
		currentX = left + (currentLocation.col * blockWidth);
		currentY += blockWidth;
	}
}

void Game::drawScore(int score, int top, int left) {

	// Score label
	sf::Text text;
	text.setFont(font);
	text.setString("Score");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(left, top);

	// Score
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString(std::to_string(score));
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::Black);
	sf::FloatRect scoreTextRect = scoreText.getLocalBounds();
	scoreText.setOrigin(scoreTextRect.left + scoreTextRect.width / 2.0f, scoreTextRect.top + scoreTextRect.height / 2.0f);
	scoreText.setPosition(sf::Vector2f(left + LAYOUT_SCORE_WIDTH / 2.0f, top + 25 + LAYOUT_SCORE_HEIGHT / 2.0f));

	// Score border
	sf::RectangleShape border(sf::Vector2f(LAYOUT_SCORE_WIDTH, LAYOUT_SCORE_HEIGHT));
	border.setOutlineColor(sf::Color::Black);
	border.setOutlineThickness(1);
	border.setFillColor(sf::Color::White);
	border.setPosition(left, top + 25);

	window.draw(border);
	window.draw(text);
	window.draw(scoreText);
	text.setString("Level");
	text.setPosition(left, top + 100);
	border.setPosition(left, top + 125);
	scoreText.setString(std::to_string(level));
	scoreText.setPosition(sf::Vector2f(left + LAYOUT_SCORE_WIDTH / 2.0f, top + 125 + LAYOUT_SCORE_HEIGHT / 2.0f));
	window.draw(text);
	window.draw(border);
	window.draw(scoreText);
}

void Game::drawNext(Tetrimino* tetrimino, int top, int left) {

	// Next piece label
	sf::Text text;
	text.setFont(font);
	text.setString("Next Piece");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(left, top);

	// Border
	sf::RectangleShape border(sf::Vector2f(LAYOUT_NEXT_WIDTH, LAYOUT_NEXT_HEIGHT));
	border.setOutlineColor(sf::Color::Black);
	border.setOutlineThickness(1);
	border.setFillColor(sf::Color::White);
	border.setPosition(left, top + LAYOUT_NEXT_TITLE_HEIGHT);

	window.draw(text);
	window.draw(border);

	// Center the next piece. Different pieces sit slightly differntly in the grid.
	Location center = getTetriminoCenter(tetrimino, BLOCK_SIZE_PIXELS);
	Location layoutCenter = {};
	layoutCenter.col = LAYOUT_NEXT_WIDTH / 2;
	layoutCenter.row = ((LAYOUT_NEXT_HEIGHT - LAYOUT_NEXT_TITLE_HEIGHT) / 2) + LAYOUT_NEXT_TITLE_HEIGHT;
	int offsetLeft = ((TETRIMINO_GRID_SIZE * BLOCK_SIZE_PIXELS) / 2) - center.col + 10;
	int offsetTop = ((TETRIMINO_GRID_SIZE * BLOCK_SIZE_PIXELS) / 2) - center.row + 10;
	drawTetrimino(tetriminoNext, LAYOUT_NEXT_TOP + offsetTop + LAYOUT_NEXT_TITLE_HEIGHT, LAYOUT_NEXT_LEFT + offsetLeft, BLOCK_SIZE_PIXELS, tetriminoBlock);
}

void Game::drawPause() {
	sf::RectangleShape box(sf::Vector2f(LAYOUT_PAUSE_WIDTH, LAYOUT_PAUSE_HEIGHT));
	box.setOutlineColor(sf::Color::Black);
	box.setOutlineThickness(1);
	box.setFillColor(sf::Color::White);
	box.setOrigin(LAYOUT_PAUSE_WIDTH / 2.0f, LAYOUT_PAUSE_HEIGHT / 2.0f);
	box.setPosition(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 2.0f);

	sf::Text text;
	text.setFont(font);
	text.setString("PAUSED");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 2.25f));

	window.draw(box);
	window.draw(text);
	text.setString("Press <P> to resume");
	text.setCharacterSize(20);
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(LAYOUT_WINDOW_WIDTH / 2.0f, LAYOUT_WINDOW_HEIGHT / 1.75f));
	window.draw(text);
}

void Game::playGame() {
	GameState currentGameState = TETRIS_SPLASH;

	while (window.isOpen()) {
		switch (currentGameState) {
		case TETRIS_SPLASH:
			processSplash();
			currentGameState = TETRIS_PLAY;
			break;
		case TETRIS_PLAY:
			processGame();
			currentGameState = TETRIS_GAME_OVER;
			break;
		case TETRIS_GAME_OVER:
			if (processGameOver()) {
				score = 0;
				level = 1;
				currentDropRate = TETRIMINO_DROP_RATE;
				music.setPitch(1.0f);
				currentGameState = TETRIS_PLAY;
			}
			else {
				window.close();
			}
			break;
		}
	}
}

void main() {
	Game game;
	game.playGame();
}