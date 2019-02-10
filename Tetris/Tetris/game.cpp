#include "game.h"
#include <iostream>

Game::Game() {
	window.create(
		sf::VideoMode(LAYOUT_WINDOW_WIDTH, LAYOUT_WINDOW_HEIGHT),
		"Tetris 2019",
		sf::Style::Titlebar | sf::Style::Close);
}

sf::Color Game::convertToSfmlColor(char color) {
	switch (color) {
	case 't':
		return sf::Color::Cyan;
		break;
	case 'b':
		return sf::Color::Blue;
		break;
	case 'o':
		return sf::Color::Magenta;
		break;
	case 'y':
		return sf::Color::Yellow;
		break;
	case 'g':
		return sf::Color::Green;
		break;
	case 'p':
		return sf::Color::Black;
		break;
	case 'r':
		return sf::Color::Red;
		break;
	default:
		return sf::Color::Transparent;
	}
}

void Game::drawWell(Well gameWell, int top, int left, int blockWidth, sf::RectangleShape block, sf::RectangleShape well) {
	char gameBoard[WELL_HEIGHT][WELL_WIDTH];
	gameWell.getBoard(gameBoard);
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

void Game::drawTetrimino(Tetrimino tetrimino, int top, int left, int blockWidth, sf::RectangleShape block) {
	int grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	tetrimino.getGrid(grid);
	Location currentLocation = tetrimino.getLocation();
	int currentX = left + (currentLocation.col * blockWidth);
	int currentY = top + (currentLocation.row * blockWidth);
	char color = tetrimino.getColor();

	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			block.setPosition(currentX, currentY);
			if (grid[row][col] == 1) {
				block.setFillColor(convertToSfmlColor(color));
				block.setOutlineThickness(1);
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

void Game::playGame() {

	// Click sound
	sf::SoundBuffer bufferClick;
	if (!bufferClick.loadFromFile("click.wav")) {
		std::cout << "Error: Cannot load click.wav" << std::endl;
	}
	sf::Sound soundClick;
	soundClick.setBuffer(bufferClick);

	// Error sound
	sf::SoundBuffer bufferError;
	if (!bufferError.loadFromFile("error.wav")) {
		std::cout << "Error: Cannot load error.wav" << std::endl;
	}
	sf::Sound soundError;
	soundError.setBuffer(bufferError);

	// Music
	sf::Music music;
	if (!music.openFromFile("tetris.ogg")) {
		std::cout << "Error: Cannot load tetris.ogg" << std::endl;
	}
	music.setVolume(10.f);
	music.setLoop(true);
	music.play();

	// Tetrimino block
	sf::RectangleShape tetriminoBlock;
	tetriminoBlock.setSize(sf::Vector2f(BLOCK_SIZE_PIXELS, BLOCK_SIZE_PIXELS));
	tetriminoBlock.setOutlineColor(sf::Color(50, 50, 50));

	// Well block
	sf::RectangleShape wellBlock;
	wellBlock.setSize(sf::Vector2f(BLOCK_SIZE_PIXELS, BLOCK_SIZE_PIXELS));
	wellBlock.setOutlineThickness(1);

	// Well
	sf::RectangleShape well;
	well.setSize(sf::Vector2f(WELL_WIDTH * BLOCK_SIZE_PIXELS, WELL_HEIGHT * BLOCK_SIZE_PIXELS));
	well.setOutlineColor(sf::Color::Black);
	well.setOutlineThickness(1);
	well.setFillColor(sf::Color::Transparent);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
				tetriminoInPlay.moveLeft();
				if (!gameWell.tetriminoFit(tetriminoInPlay)) {
					tetriminoInPlay.moveRight();
					soundError.play();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
				tetriminoInPlay.moveRight();
				if (!gameWell.tetriminoFit(tetriminoInPlay)) {
					tetriminoInPlay.moveLeft();
					soundError.play();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
				tetriminoInPlay.rotateRight();
				if (!gameWell.tetriminoFit(tetriminoInPlay)) {
					tetriminoInPlay.rotateLeft();
					soundError.play();
				}
				soundClick.play();
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
		}

		window.clear(sf::Color::White);
		drawWell(gameWell, LAYOUT_BOARD_TOP, LAYOUT_BOARD_LEFT, BLOCK_SIZE_PIXELS, wellBlock, well);
		drawTetrimino(tetriminoInPlay, LAYOUT_BOARD_TOP, LAYOUT_BOARD_LEFT, BLOCK_SIZE_PIXELS, tetriminoBlock);
		window.display();
	}
}

void main() {
	Game game;
	game.playGame();
}