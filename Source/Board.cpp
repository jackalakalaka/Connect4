#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Player.h"
#include "Board.h"
#undef max
#undef min


//Constructor that sets all spots to empty with underscores
Board::Board()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			columns[i][j] = '_';
		}//end j for
	}//end i for
}//end Board constructor



//Function that takes in player object, with its memeber "jChoice", and
//alters board accordingly
void Board::writeBoard(Player p)
{
	//j represents column chosen
	int j = p.jChoice - 1;

	//While loop that starts from the bottom of chosen column. When an empty
	//space is reached, it is filled with the player's piece.
	int i = 5;
	while (columns[i][j] != '_')
	{
		//Decrements empty space scanner if there are more spaces to scan
		if (i > 0)
		{
			i--;
		}//end if

		//Cancel's process if column is full
		else if (columns[i][j] != '_')
		{
			std::cout << "Fool! The full column left the piece with nowhere"
				<< " to go, losing it in the process.\n";
			//Setting iChoice to -1 indicates to winCheck to break right away
			p.iChoice = -1;
			return;
		}//end else if
	}//end while
	columns[i][j] = p.piece;
	//Remembers row piece was placed in
	p.iChoice = i;
}//end writeBoard (add error if column is full)



//Function that checks if game is won or if board is full; if so, returns a
//boolean 1. This function should be called after writeBoard.
bool Board::winCheck(Player p)
{
	//Doesn't run if the chosen column was full aka if i.choice was set to
	//equal -1 to indicate this
	if (p.iChoice == -1)
	{
		return 0;
	}

	//Simplifies column & row choice names as well as piece symbol
	int j = p.jChoice - 1;
	int i = p.iChoice;
	char sym = p.piece;

	//Horizontal win checking:
	//Checks for horizontal win right from j 3 spaces
	if (j <= 3)
	{
		if (columns[i][j + 1] == sym && columns[i][j + 2] == sym
			&& columns[i][j + 3] == sym)
		{
			std::cout << "4 in a row - " << p.name << " has won!\n";
			return 1;
		}//end if
	}//end if
	//Checks for horizontal win right from j 2 spaces and left 1 space
	if (j <= 4 && j >= 1)
	{
		if (columns[i][j + 1] == sym && columns[i][j + 2] == sym
			&& columns[i][j - 1] == sym)
		{
			std::cout << "4 in a row - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for horizontal win right from j 1 space and left 2 spaces
	if (j <= 5 && j >= 2)
	{
		if (columns[i][j + 1] == sym && columns[i][j - 1] == sym
			&& columns[i][j - 2] == sym)
		{
			std::cout << "4 in a row - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for horizontal win left from j 3 spaces
	if (j >= 3)
	{
		if (columns[i][j - 1] == sym && columns[i][j - 2] == sym
			&& columns[i][j - 3] == sym)
		{
			std::cout << "4 in a row - " << p.name << " has won!\n";
			return 1;
		}
	}//end if

	//Vertical win checking:
	//Checks for vertical win above from i 3 spaces
	if (i >= 3)
	{
		if (columns[i - 1][j] == sym && columns[i - 2][j] == sym
			&& columns[i - 3][j] == sym)
		{
			std::cout << "4 in a column - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for vertical win above from i 2 spaces and below 1 space
	if (i >= 2 && i <= 4)
	{
		if (columns[i - 1][j] == sym && columns[i - 2][j] == sym
			&& columns[i + 1][j] == sym)
		{
			std::cout << "4 in a column - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for vertical win above from i 1 space and below 2 spaces
	if (i >= 1 && i <= 3)
	{
		if (columns[i - 1][j] == sym && columns[i + 1][j] == sym
			&& columns[i + 2][j] == sym)
		{
			std::cout << "4 in a column - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for vertical win below from i 3 spaces
	if (i <= 2)
	{
		if (columns[i + 1][j] == sym && columns[i + 2][j] == sym
			&& columns[i + 3][j] == sym)
		{
			std::cout << "4 in a column - " << p.name << " has won!\n";
			return 1;
		}
	}//end if

	//Positive slope diagonal win checking:
	//Checks for positive diagonal win above space by 3
	if (j <= 3 && i >= 3)
	{
		if (columns[i - 1][j + 1] == sym && columns[i - 2][j + 2] == sym
			&& columns[i - 3][j + 3] == sym)
		{
			std::cout << "4 in a diagonal - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for positive diagonal win above space by 2 and below by 1
	if (j <= 4 && j >= 1 && i >= 2 && i <= 4)
	{
		if (columns[i - 1][j + 1] == sym && columns[i - 2][j + 2] == sym
			&& columns[i + 1][j - 1] == sym)
		{
			std::cout << "4 in a diagonal - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for positive diagonal win above space by 1 and below by 2
	if (j <= 5 && j >= 2 && i >= 1 && i <= 3)
	{
		if (columns[i - 1][j + 1] == sym && columns[i + 1][j - 1] == sym
			&& columns[i + 2][j - 2] == sym)
		{
			std::cout << "4 in a diagonal - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for positive diagonal win below space by 3
	if (j >= 3 && i <= 2)
	{
		if (columns[i + 1][j - 1] == sym && columns[i + 2][j - 2] == sym
			&& columns[i + 3][j - 3] == sym)
		{
			std::cout << "4 in a diagonal - " << p.name << " has won!\n";
			return 1;
		}
	}//end if

	//Negative slope diagonal win checking:
	//Checks for negative diagonal win above space by 3
	if (j >= 3 && i >= 3)
	{
		if (columns[i - 1][j - 1] == sym && columns[i - 2][j - 2] == sym
			&& columns[i - 3][j - 3] == sym)
		{
			std::cout << "4 in a diagonal - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for negative diagonal win above space by 2 and below by 1
	if (j >= 2 && j <= 5 && i >= 2 && i <= 4)
	{
		if (columns[i - 1][j - 1] == sym && columns[i - 2][j - 2] == sym
			&& columns[i + 1][j + 1] == sym)
		{
			std::cout << "4 in a diagonal - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for negative diagonal win above space by 1 and below by 2
	if (j >= 1 && j <= 4 && i >= 1 && i <= 3)
	{
		if (columns[i - 1][j - 1] == sym && columns[i + 1][j + 1] == sym
			&& columns[i + 2][j + 2] == sym)
		{
			std::cout << "4 in a diagonal - " << p.name << " has won!\n";
			return 1;
		}
	}//end if
	//Checks for negative diagonal win below space by 3
	if (j <= 3 && i <= 2)
	{
		if (columns[i + 1][j + 1] == sym && columns[i + 2][j + 2] == sym
			&& columns[i + 3][j + 3] == sym)
		{
			std::cout << "4 in a diagonal - " << p.name << " has won!\n";
			return 1;
		}
	}//end if

	//If no wins are detected, return false
	return 0;
}//end winCheck


//Function that checks if board is full by examining top row of board
bool Board::fullCheck()
{
	//Scans the top row
	for (int i = 0; i < 7; i++)
	{
		//Board is not full if any underscores aka empty spaces are detected
		if (columns[i][0] == '_')
		{
			return 0;
		}//end if
	}//end for

	//If there are no underscores detected, board is full
	std::cout << "The board is full - the game was a draw!\n";
	return 1;
}//end fullCheck

//Function that displays the current array of pieces aka the board
void Board::printBoard()
{
	for (int i = 0; i < 6; i++)
	{
		std::cout << "]";
		for (int j = 0; j < 7; j++)
		{
			std::cout << columns[i][j];
			//Keeps grid spacing from extending in between right-side
			//brackets and gridspaces
			if (j < 6)
			{
				std::cout << " ";
			}
		}//end j for
		std::cout << "[\n";
	}//end i for
	std::cout << "\n";
}//endl printBoard