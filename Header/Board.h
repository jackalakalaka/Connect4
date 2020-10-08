
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Player.h"
#undef max
#undef min


class Board
{
public:
	//Initialize 6x7 array that represents board (need to be public?)
	//Columns are 0=leftmost -> 6=rightmost. Rows are 0=top -> 5=bottom
	char columns[6][7];

	//Constructor that sets all spots to empty with underscores
	Board();

	//Function that takes in player object, with its memeber "jChoice", and
	//alters board accordingly
	void writeBoard(Player p);

	//Function that checks if game is won or if board is full; if so, returns a
	//boolean 1. Should be called after writeBoard.
	bool winCheck(Player p);

	//Function that checks if board is full by examining top row of board
	bool fullCheck();

	//Function that displays the current array of pieces aka the board
	void printBoard();
};