#pragma once

#include "Game.h"

class TicTacToe : public Game {

public:
	void Display() const {
		//Display Board
		std::cout
			<< board[0] << "|" << board[1] << "|" << board[2] << "\n"
			<< "------" << "\n"
			<< board[3] << "|" << board[4] << "|" << board[5] << "\n"
			<< "------" << "\n"
			<< board[6] << "|" << board[7] << "|" << board[8] << "\n"
			<< "------" << "\n";
	}
	bool IsGameOver() const {

		//Check For Diagonal Wins
		if (board[0] == board[4] && board[4] == board[8]) { std::cout << "Player " << player << " has won! "; return true; }
		if (board[2] == board[4] && board[4] == board[6]) { std::cout << "Player " << player << " has won! "; return true; }

		//Check For Veritcal Wins
		if (board[0] == board[3] && board[3] == board[6]) { std::cout << "Player " << player << " has won! "; return true; }
		if (board[1] == board[4] && board[4] == board[7]) { std::cout << "Player " << player << " has won! "; return true; }
		if (board[2] == board[5] && board[5] == board[8]) { std::cout << "Player " << player << " has won! "; return true; }

		//Check For Horizontal Wins
		if (board[0] == board[1] && board[1] == board[2]) { std::cout << "Player " << player << " has won! "; return true; }
		if (board[3] == board[4] && board[4] == board[5]) { std::cout << "Player " << player << " has won! "; return true; }
		if (board[6] == board[7] && board[7] == board[8]) { std::cout << "Player " << player << " has won! "; return true; }

		//Since no one won yet, check if board is full; if so, game is over.
		if (turn == 9) { std::cout << "It's a tie! ";  return true; }

		//If none of the above have returned true, the game is still on.
		return false;
	}
	virtual void TakeTurn() {

		//Set Player character - Player O plays on even turns, Player X on odd turns
		if (turn % 2 == 0) {
			player = 'O';
		}
		else {
			player = 'X';
		}

		//Loop Through Spot Selection Until a Valid Place is Selected
		bool invalidInput = true;
		int place;
		while (invalidInput) {
			//Get Players Selected Space
			std::cout << "Player " << player << ", where would you like to go? (Enter the Number for the Square): ";
			std::cin >> place;

			//Convert input from a num 1-9 (board displayed) to a num 0-8 (array position)
			place--;

			if (board[place] == 'X' || board[place] == 'O') {
				//Invalid Input - Notify User and allow loop to loop
				std::cout << "Sorry, that square is taken or that value is invalid.\n";
			}
			else {
				//Valid Input - Update Board and end the loop
				std::cout << "\n";
				board[place] = player;
				invalidInput = false;
			}
		}
		
		//Increment Turn Counter
		turn++;
	}
private:
	//Variables to track the state of the game
	int turn = 0;
	char player = 'O';
	char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};