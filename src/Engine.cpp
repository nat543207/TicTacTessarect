/*
 * main.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: nat543207
 */
#include <iostream>
#include <string>
#include <limits>
#include "../headers/Engine.h"
#include "../headers/Rules.h"
#include "../headers/Generalization.h"
#include "../headers/UI.h"

void configure();

int main()
{
	configure();
	UI_Handler ui;
	ui.text_buildBoard(sideLength, dimensions);
	ui.text_printBoard();
	p = new Player[numberOfPlayers];
	currentPlayer = &p[0];

	for(unsigned i = 0; i < numberOfPlayers; i++)
	{
		//Initializer loop for each Player's instance variables
		std::cout << "Player " << i + 1 << ", please enter the symbol that will mark your moves:" << std::endl;
		char a;
		std::cin >> a;
		p[i].setMark(a);
		p[i].setNextPlayer(p[(i + 1) % numberOfPlayers]); //wraps around the end of the array, setting last Player's nextPlayer as the first Player
		p[i].setID(minID + i);
	}

	do
	{
		if(currentPlayer->getID() == minID)
			turnNumber++;
		std::cout << "Player " << currentPlayer->getMark() << " to move." << std::endl;
		currentPlayer->makeMove();
		currentPlayer = &(currentPlayer->getNextOpponent());
	}
	while(!currentPlayer->getNextOpponent().wins());

	delete[] p;
}

void configure()
{
	bool cfg_success = false;
	int cfg_vals[3];

	while(!cfg_success)
	{
		std::cout << "You can either customize your game's parameters, or select from "
				"an existing configuration.  Customize? (y/N):  ";

		std::string cfg_opt;
		getline(std::cin, cfg_opt);

		switch(cfg_opt[0])
		{
			case 'n':
			case 'N':
			case '\0':
			{
				std::cout << "\nEnter the number of the configuration you'd like to play:\n"
						"1:  3x3 2-player game\n"
						"2:  5x5 2-player game\n"
						"3:  5x5x5x5 2-player game\n"
						"4:  5x5x5x5 4-player game\n";

				std::string cfg_num;
				std::cin >> cfg_num;

				switch(cfg_num[0])
				{
					case '1':
						numberOfPlayers = 2;
						sideLength = 3;
						dimensions = 2;
						break;
					case '2':
						numberOfPlayers = 2;
						sideLength = 5;
						dimensions = 2;
						break;
					case '3':
						numberOfPlayers = 2;
						sideLength = 5;
						dimensions = 4;
						break;
					case '4':
						numberOfPlayers = 4;
						sideLength = 5;
						dimensions = 4;
						break;
					default:
						std::cout << "Invalid option.  Please try again.";
						continue;
				}
				cfg_success = true;
				break;
			}

			case 'y':
			case 'Y':
			{
				std::string cfg_msgs[] = 	{"How many people are playing?",
						"How many cells would you like in each row, column, and diagonal?",
						"How many dimensions would you like the board to span?"};

				while(!cfg_success)
				{
					for(int i = 0; i < 3; i++)
					{
						std::cout << cfg_msgs[i] << std::endl;
						std::cin >> cfg_vals[i];
					}

					try
					{
						numberOfPlayers = cfg_vals[0];
						sideLength = cfg_vals[1];
						dimensions = cfg_vals[2];
					}
					catch(std::exception &e)
					{
						std::cout << "I'm sorry, but one of the values that you entered invalid.  Please try again." << std::endl;
						continue;
					}
					cfg_success = true;
				}
				break;
			}
			default:
				std::cout << "I'm sorry, but the option you entered is invalid.  Please try again." << std::endl;
				continue;
		}
	}
}
