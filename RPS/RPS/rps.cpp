/*
Rock Paper Scissors Game!
*/

#include <iostream>
#include <ctime> // for random number generation
#include <cstdlib> // for random number generation
#include <string>

using namespace std;

enum HandState { ROCK, PAPER, SCISSORS };

void welcome();
HandState getComputerChoice();
HandState getPlayerChoice();
void checkWinner(HandState playerChoice, HandState computerChoice);
bool userWantsToPlayAgain();

void main() {
	HandState computer;
	HandState player;

	// seed the random number generator
	srand(time(NULL));

	welcome();

	do {
		computer = getComputerChoice();
		player = getPlayerChoice();
		checkWinner(player, computer);

	} while (userWantsToPlayAgain());
}

/*
Function Name:	welcome
Description:	welcomes the player to the game and states the rules
Arguments:		none
Return:			none
*/
void welcome() {
	cout << "Welcome to the CS 161 Rock, Paper, Scissors Game!" << endl;
	cout << "The rule are simple: " << endl << "Rock smashes scissors; Paper covers rock; Scissors cut paper." << endl << endl;
}

/*
Function Name:	getComputerChoice
Description:	Generates a random value (either rock, paper, or scissors) for the computer
Arguments:		none
Return:			a HandState value (the computer's choice)
*/
HandState getComputerChoice() {
	int randomNum;

	// generate a random number between 1 and 3 for the computer's hand choice
	// 1 is rock, 2 is paper, 3 is scissors
	randomNum = (rand() % 3) + 1;
	if (randomNum == 1)
		return ROCK;
	else if (randomNum == 2)
		return PAPER;
	else
		return SCISSORS;
}

/*
Function Name:	getPlayerChoice
Description:	Gets the player's choice (rock, paper, or scissors)
Arguments:		none
Return:			a HandState value (the player's choice)
*/
HandState getPlayerChoice() {
	// get the player's choice (rock, paper, or scissors)
	// make sure you prompt until a valid choice is entered and return the value at the end

		// ***** STUDENTS DO THIS PART *****

//	HandState playerHandState;
	string playerHand;
	bool tryAgain = false;

	do {
		cout << "Please enter the hand you want to play (ROCK / PAPER / SCISSORS): ";
		cin >> playerHand;

		if (playerHand == "ROCK") {
			return ROCK;
		}
		if (playerHand == "PAPER") {
			return PAPER;
		}
		if (playerHand == "SCISSORS") {
			return SCISSORS;
		}
		else {
			cout << "That is not a valid hand.\n";
			tryAgain = true;
		}
	} while (tryAgain);
}

/*
Function Name:	checkWinner
Description:	States who won this round and prints the player's running win/loss record
Arguments:		2 HandState values (the first is the player's, the second is the computer's)
Return:			none
*/
void checkWinner(HandState playerChoice, HandState computerChoice) {
	static int numWins = 0;
	static int numLosses = 0;

	// Since the player and computer each have 3 choices, there are 9 different scenarios possible
	// Check for each of them and print the winner in each case
	// Also update the numWins and numLosses as appropriate

	// ***** STUDENTS DO THIS PART *****

	if (playerChoice == computerChoice) {
		cout << "It was a tie\n";
	}
	else if ((playerChoice == ROCK && computerChoice == SCISSORS) || (playerChoice == PAPER && computerChoice == ROCK) || (playerChoice == SCISSORS && computerChoice == PAPER)) {
		cout << "You win!\n";
		numWins++;
	}
	else {
		cout << "You lose.\n";
		numLosses++;
	}

	// Print the player's record
	cout << endl << "Your record is " << numWins << " wins and " << numLosses << " losses." << endl;
	if (numWins >= numLosses)
		cout << "That's not too bad." << endl;
	else
		cout << "You're not very good at this, are you?" << endl;
}

/*
Function Name:	userWantsToPlayAgain
Description:	Checks to see if the player wants to keep playing the game
Arguments:		none
Return:			bool - true if the user wants to play again, false otherwise
*/
bool userWantsToPlayAgain() {
	char playAgain = 'N';
	cout << endl << "That was fun! Would you like to play again? (Y/N): ";
	cin >> playAgain;
	cin.ignore(100, '\n');
	// make sure we got a valid response
	while (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n')
		cout << "That is an invalid option! Would you like to play again? (Y/N): ";
	if (playAgain == 'Y' || playAgain == 'y')
		return true;
	else
		return false;
}