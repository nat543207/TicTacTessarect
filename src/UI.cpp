/*
 * UI.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: nat543207
 */

#include "../headers/Generalization.h"
#include <iostream>

const char board[] =	"  _ | _ | _\n"
						" ---+---+---\n"
						"  _ | _ | _\n"
						" ---+---+---\n"
						"  _ | _ | _\n";

extern Player p[];
//extern Player* currentPlayer;

void printBoard()
{
	for(int i = 0; i < 65 /*<- board length*/; i++)
		std::cout << board[i];
}

int* getMoveCoordinates()
{
	int* input = new int[dimensions];

		for(int i = dimensions - 1; 0 <= i; i--)
		{
			std::cout << "Enter coordinates of move for dimension " << i << std::endl;
			std::cin >> input[i];
		}

	std::cout << "Move received." << std::endl;
	return input;
}

bool moveIsValid(int move)
{
	std::cout << currentPlayer->getID() << std::endl;

	for(unsigned i = currentPlayer->getID(); i < numberOfPlayers; i++)
	{
		for(unsigned j = 0; j < turnNumber; j++)
		{
			if(magicSquare[move] == (p[i % numberOfPlayers])[j])
			{
				std::cout << "Space is occupied.  Please choose another.";
				return true;
			}
		}
		currentPlayer = &(currentPlayer->getNextOpponent());
	}
	return false;
}

void addToBoard(const int move)
{
//	std::fstream board;
//	board.open("../resources/board.default");
//	const char* file = "../resources/board.default";
//	const char* mode = "r";
//	int j = 0;
//	for(int i = 0; i < move; j++)
//	{
//		//TODO Get each character sequentially (may skip whitespace), count the number of delimiter ('?') characters
//		if(std::fgetc(fopen(file, mode)) == '?')
//			i++;
//	}
	//TODO Assign character in position the mark of the current player
}
