#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Player.h"
#include "Board.h"
#undef max
#undef min


int main()
{
	//Sets up prompt for restart option
	bool restart = 1;
	while (restart == 1)
	{
		//Initializes board, players, win & full-board checkers
		Board board;
		Player p1, p2;
		bool win = 0;
		bool full = 0;

		//Explains game
		std::cout << "Welcome to Connect Four! The goal of the game is to line \n";
		std::cout << "up 4 consecutive pieces either horizontally, vertically, \n";
		std::cout << "or diagonally before your opponent. To select a column, \n";
		std::cout << "enter one of the corresponding numbers as shown below.\n\n";
		std::cout << " 1 2 3 4 5 6 7\n";
		board.printBoard();

		//Asks for and writes players' names
		std::cout << "Player 1, what is your name?" << std::endl;
		std::cin >> p1.name;
		std::cout << "Player 2, what is your name?" << std::endl;
		std::cin >> p2.name;

		//Players pick what symbol their piece will be
		std::cout << p1.name << ", what symbol will represent your piece?\n";
		std::cin >> p1.piece;
		std::cout << p2.name << ", what symbol will represent your piece?\n";
		std::cin >> p2.piece;

		//Takes a second to randomly select first-turn player using ctime-seeded rand
		std::cout << "Calculating who will go first...\n";
		//Sleeps for 1.5s
		Sleep(1500);
		//Randomly selects first player
		srand((unsigned int)time(NULL));
		p1.order = rand() % 2 + 1;
		//Player orders written to both player objects
		if (p1.order == 1)
		{
			p2.order = 2;
			std::cout << p1.name << " goes first!\n";
		}//end if
		else
		{
			p2.order = 1;
			std::cout << p2.name << " goes first!\n";
		}//end else

		//Waits a second to begin the game
		std::cout << "Beginning game.\n\n";
		Sleep(1000);

		//*debug: Board prints properly empty

		//Alternates turns until the game is won or board is full
		int	turnCount = 0;
		while (win == 0 && full == 0)
		{
			//Decides whose turn it is
			if (p1.order == turnCount % 2 + 1)
			{
				std::cout << p1.name << ", in which column do you drop your piece?\n";
				//If column jChoice is outside valid range, takes in new jChoice.
				while (p1.jChoice < 1 || p1.jChoice > 7)
				{
					//Makes sure jChoice input is an integer
					while (!(std::cin >> p1.jChoice))
					{
						std::cout << "Invalid entry. Please enter an integer\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					}//end jChoice data type checking while

					//Reprompts user if column entry is not between 1 and 7
					if (p1.jChoice < 1 || p1.jChoice > 7)
					{
						std::cout << "Invalid columnn number - please enter one";
						std::cout << " including or between 1 and 7\n";
					}//end if
				}//end jChoice value checking while while

				//Passes player, with current column choice, to writeBoard
				//Retrieves the resultant row placement of piece
				board.writeBoard(p1);
				//* - p1.iChoice = board.writeBoard(p1);
				//Displays current board
				board.printBoard();
				//Checks if there is a win
				win = board.winCheck(p1);
				//Checks if board is full
				full = board.fullCheck();

				//Re-invalidates column choice so that the while loop, which
				//contains the insput stream, is in effect
				p1.jChoice = 0;

				turnCount++;
			}//end if
			else
			{
				std::cout << p2.name << ", in which column do you drop your piece?\n";
				//If column jChoice is outside valid range, takes in new jChoice.
				while (p2.jChoice < 1 || p2.jChoice > 7)
				{
					//Makes sure jChoice input is an integer
					while (!(std::cin >> p2.jChoice))
					{
						std::cout << "Invalid entry. Please enter an integer";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n');
					}//end jChoice data type checking while

					//Reprompts user if column entry is not between 1 and 7
					if (p2.jChoice < 1 || p2.jChoice > 7)
					{
						std::cout << "Invalid columnn number - please enter one";
						std::cout << " including or between 1 and 7\n";
					}//end if
				}//end jChoice value checking while while

				//Passes player, with current column choice, to writeBoard
				//Retrieves resultant row placement of piece
				board.writeBoard(p2);
				//* - p2.iChoice = board.writeBoard(p2);
				//Displays current board
				board.printBoard();
				//Checks if there is a win
				win = board.winCheck(p2);
				//std::cout << "win: " << win << endl;
				//Checks if board is full
				full = board.fullCheck();

				//Re-invalidates column choice so that the while loop, which
				//contains the insput stream, is in effect
				p2.jChoice = 0;

				turnCount++;
			}//end else
		}//end turns while

		//Prompts for restart
		std::cout << "\nPlay again? (y or n) ";
		//B meme
		char restartChar = 'B';
		while (restartChar != 'y' && restartChar != 'n')
		{
			std::cin >> restartChar;
			if (restartChar == 'y')
			{
				restart = 1;
				std::cout << "\n\n\n";
			}//end affirmative if
			if (restartChar == 'n')
			{
				restart = 0;
			}//end negative if
			if (restartChar != 'y' && restartChar != 'n')
			{
				std::cout << "Invalid entry - enter 'y' or 'n'\n";
			}//end invalid entry if
		}//end while
	}//end restart while
}//end main