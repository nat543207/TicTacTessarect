/*
 * main.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: nat543207
 */
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include "../headers/Engine.h"
#include "../headers/Player.h"
#include "../headers/Generalization.h"
#include "../headers/UI.h"
#include "../headers/MagicSquareGenerator.h"

void configure();

int main()
{
	configure();
//	Magic_Cube mc(dimensions, sideLength, false, 1);
//	for(int i = 0; i < mc.Table_Size; i++)
//	{
//		std::cout << mc.Lookup_Table[i] << ' ';
//	}
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
 * Allows players to customize game, eventually.  For now, it just presents them with the presets that can be played.
 */
void configure()
{
	bool cfg_success = false;

	//Locks player in configuration menu until configuration is successful
	while(!cfg_success)
	{
		std::cout << "You can either customize your game's parameters, or select from "
				"an existing configuration.  Customize? (y/N):  ";

		std::string cfg_opt;
		std::cin >> cfg_opt;

		//Checks if player wants to customize game; default is no.
		switch(cfg_opt[0])
		{
			case 'n':
			case 'N':
			case '\0':
			{
				//Presents preset games that players can play
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
						break;
					case '2':
						numberOfPlayers = 3;
						sideLength = 3;
						dimensions = 2;
						break;
					case '3':
						numberOfPlayers = 2;
						sideLength = 3;
						dimensions = 4;
						break;
					case '4':
						numberOfPlayers = 3;
						sideLength = 3;
						dimensions = 4;
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
			{
				std::cout << "Feature not yet supported.  Please choose from one of the available presets.\n";
//				int cfg_vals[3];
//				std::string cfg_msgs[] = 	{"How many people are playing?",
//						"How many cells would you like in each row, column, and diagonal?",
//						"How many dimensions would you like the board to span?"};
//
//				while(!cfg_success)
//				{
//					for(int i = 0; i < 3; i++)
//					{
//						std::cout << cfg_msgs[i] << std::endl;
//						std::cin >> cfg_vals[i];
//					}
//
//					try
//					{
//						numberOfPlayers = cfg_vals[0];
//						sideLength = cfg_vals[1];
//						dimensions = cfg_vals[2];
//					}
//					catch(std::exception &e)
//					{
//						std::cout << "I'm sorry, but one of the values that you entered invalid.  Please try again." << std::endl;
//						continue;
//					}
//					cfg_success = true;
//				}
				break;
			}
			default:
				std::cout << "I'm sorry, but the option you entered is invalid.  Please try again." << std::endl;
				continue;
		}
	}
	magicSum = sideLength * (pow(sideLength, dimensions) + 1) / 2;
}
