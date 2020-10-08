#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#undef max
#undef min


class Player
{
public:
	//Player's piece symbol
	char piece;
	//Name of player
	std::string name;
	//Whether player is first or second
	int order;
	//Represents which column, 1-7, player chose to drop piece in for turn
	int jChoice;
	//Represents which row the player's piece ended up in; depends on jChoice
	int iChoice;

	//Constructor that initializes an invalid cloumn so that a while loop runs (name the line number)
	Player() { jChoice = 0; iChoice = -1; };
};