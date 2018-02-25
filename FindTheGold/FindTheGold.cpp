// FindTheGold.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>    
#include <cstdlib>    
#include <ctime>    

using namespace std;   

const int NUM_ROWS = 8;
const int NUM_COLS = 8;
const int NUM_LIVES = 5;
const int ITEMS_TO_BURY = 5;
const int PLACED_BOMB = 1;

void initBoard(char board[NUM_ROWS][NUM_COLS]);
void hideTreasures(char board[NUM_ROWS][NUM_COLS]);
void gameRules();
void guessLocations(char board[NUM_ROWS][NUM_COLS]);


int main()
{
	// The 2-D array
	char board[NUM_ROWS][NUM_COLS];
	char answer;
	do
	{
		initBoard(board);
		hideTreasures(board);
		gameRules();
		guessLocations(board);

		cout << "Play Again? Enter 'y' ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');

	return 0;
}
	

void initBoard(char board[NUM_ROWS][NUM_COLS])
{
	int row, col;

	// Clear each location on the island so the whole array is "blank"
	for (row = 0; row < NUM_ROWS; row++)
	{
		for (col = 0; col < NUM_COLS; col++)
		{
			board[row][col] = '?';
			//cout << board[NUM_ROWS][NUM_COLS];
		}
	}
} 
void hideTreasures(char board[NUM_ROWS][NUM_COLS])
{
	int gold = 0;
	int x, y;
	int bomb = 0;
	srand(time(NULL));

	// Hide some treasure in three random places

	for (gold = 0; gold < ITEMS_TO_BURY; gold++)
	{
		x = rand() % NUM_ROWS;
		y = rand() % NUM_COLS;
		board[x][y] = 'G';
	}  // end of for loop

	for (bomb = 0; bomb < PLACED_BOMB; bomb++)
	{
		x = rand() % NUM_ROWS;
		y = rand() % NUM_COLS;
		board[x][y] = 'B';
	}
}

		void gameRules()
		{
			cout << endl;
			cout << "*****" << " ************************* " << "*****" << endl;
			cout << "*****" << " Try to Find Gold " << "*****" << endl;
			cout << "*****" << " You have 5 Guesses" << "*****" << endl;
			cout << "*****" << " 5 pieces of gold " << "*****" << endl;
			cout << "*****" << " and 1 bomb " << "*****" << endl;
			cout << "*****" << " Good Luck! " << "*****" << endl;
			cout << "*****" << " ************************* " << "*****" << endl;
			cout << endl;
		}
	
		void guessLocations(char board[NUM_ROWS][NUM_COLS])
		{
			// Allow user to repeatedly guess a place where the treasure is hidden
			int rowGuessed, colGuessed;
			int guessesLeft = NUM_LIVES;
			int points = 0;
			//ends here, may have to put another } bracket 

			while (guessesLeft > 0)
			{
				cout << "Enter X Coordinate: 1-" << NUM_COLS << ": ";
				cin >> rowGuessed;
				cout << "Enter Y Coordinate: 1-" << NUM_ROWS << ": ";
				cin >> colGuessed;

				// Check whether any treasure is buried where the user guessed
				if (board[rowGuessed][colGuessed] == 'G')
				{
					cout << "You Found GOLD!";
					board[rowGuessed][colGuessed] = 'F';
					points = points + 1;
					guessesLeft--;
					cout << "\t" << " You have " << guessesLeft << " guesses left " << endl;
					cout << endl;
					continue;
				}
				else if (board[rowGuessed][colGuessed] == 'B')
				{
					cout << endl;
					guessesLeft = 0;
					cout << " You found a Bomb... " << "The game is over " << endl;
					break;
				}
				else
					cout << "Uh ohh.. NO gold there ";
				guessesLeft--;
				cout << "\t" << "You have " << guessesLeft << " guesses left " << endl;
			}

			cout << "You earned " << points << " points " << endl;
			cout << "Good luck next time " << endl;
			cout << " Here is the next board if you wish to keep playing " << endl;
			cout << endl;
		}

		
			
