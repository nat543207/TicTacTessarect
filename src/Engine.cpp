/*
 * Engine.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: nat543207
 *
 * A file that contains the game's engine and configuration methods.  Everything else is called from
 * within here.
 */
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include "../headers/Engine.h"
#include "../headers/Player.h"
#include "../headers/Generalization.h"
#include "../headers/UI.h"

void configure();

int main()
{
	configure();
	p = new Player[numberOfPlayers];
	currentPlayer = &p[0];
	char* usedSyms = new char[numberOfPlayers];

	//Initializer loop for each Player's instance variables
	for(int i = 0; i < numberOfPlayers; i++)
	{
		std::cout << "Player " << i + 1 << ", please enter the symbol that will mark your moves:" << std::endl;
		char c;
		std::cin >> c;
		bool success = true;
		for(int j = 0; j < i; j++)
		{
			if(c == usedSyms[j])
			{
				std::cout << "That symbol is already used.  Please enter another.";
				success = false;
				break;
			}
		}
		if(!success)
			continue;

		p[i].setMark(c);
		usedSyms[i] = c;
		p[i].setNextPlayer(p[(i + 1) % numberOfPlayers]); //wraps around the end of the array, setting last Player's nextPlayer as the first Player
		p[i].setID(minID + i);
	}
	delete[] usedSyms;

	UI_Handler ui;
	ui.text_buildBoard(sideLength, dimensions);
	ui.text_printBoard();

	//Game loop.  This repeats until one player wins.
	while(true)
	{
		if(currentPlayer->getID() == minID)
			turnNumber++;
		std::cout << "Player " << currentPlayer->getMark() << " to move." << std::endl;
		currentPlayer->makeMove();

		//Breaks out of game loop
		if(currentPlayer->wins())
			break;
		currentPlayer = &(currentPlayer->getNextOpponent());
	}

	std::cout << "Player " << currentPlayer->getMark() << " wins!";
	delete[] p;
}

/*
 * Allows users to customize game, eventually.  For now, it just presents them with the presets that can be played.
 */
void configure()
{
	bool cfg_success = false;

	//Locks user in configuration menu until configuration is successful
	while(!cfg_success)
	{
		std::cout << "You can either customize your game's parameters, or select from "
				"an existing configuration.  Customize? (y/N):  ";

		std::string cfg_opt;
		std::cin >> cfg_opt;

		//Checks if user wants to customize game; default is no.
		switch(cfg_opt[0])
		{
			case 'n':
			case 'N':
			case '\0':
			{
				//Presents preset games that users can play
				std::cout << "\nEnter the number of the configuration you'd like to play:\n"
						"1:  3x3 2-player game\n"
						"2:  3x3 3-player game\n"
						"3:  3x3x3x3 2-player game\n"
						"4:  3x3x3x3 3-player game\n";

				std::cin >> cfg_opt; //Sanitize

				//Hard-coded configurations for above options
				switch(cfg_opt[0])
				{
					case '1':
						numberOfPlayers = 2;
						sideLength = 3;
						dimensions = 2;
						magicArray = &magicSquare[0];
						break;
					case '2':
						numberOfPlayers = 3;
						sideLength = 3;
						dimensions = 2;
						magicArray = &magicSquare[0];
						break;
					case '3':
						numberOfPlayers = 2;
						sideLength = 3;
						dimensions = 4;
						magicArray = &magicTessarect[0];
						break;
					case '4':
						numberOfPlayers = 3;
						sideLength = 3;
						dimensions = 4;
						magicArray = &magicTessarect[0];
						break;
					default:
						std::cout << "Invalid option.  Please retry configuration.\n\n";
						continue;
				}
				cfg_success = true;
				break;
			}

			case 'y':
			case 'Y':
				std::cout << "Feature not yet supported.  Please choose from one of the available presets.\n";
				break;
			default:
				std::cout << "I'm sorry, but the option you entered is invalid.  Please try again." << std::endl;
				continue;
		}
	}
	//Calculate which value will be the sum of the magic square's rows, columns, and diagonals
	magicSum = sideLength * (pow(sideLength, dimensions) + 1) / 2;
}
