/*
 * Generalization.cpp
 *
 *  Created on: Mar 15, 2014
 *      Author: nat543207
 *
 *      Global variables.  Consts need to be renamed to follow C++ naming conventions, but until I get the bugs ironed out
 *      so that the program compiles, I'm not messing with it.  Also, I don't know what I'm doing with extern except that
 *      it lets me declare the variables here and access them everywhere else by including the headder.
 */
#include "../headers/Generalization.h"

unsigned numberOfPlayers = 0;
unsigned sideLength = 3;
unsigned dimensions = 2;
unsigned magicSum = 15;
unsigned magicSquare[] =	{2, 7, 6,
							 9, 5, 1,
							 4, 3, 8};

unsigned magicTessarect[] =	{52, 66,  5,  60, 26, 37,  11, 31, 81,
							  2, 49, 72,  43, 57, 23,  78, 17, 28,
							 69,  8, 46,  20, 40, 63,  34, 75, 14,

							  3, 50, 70,  44, 55, 24,  76, 18, 29,
							 67,  9, 47,  21, 41, 61,  35, 73, 15,
							 53, 64,  6,  58, 27, 38,  12, 32, 79,

							 68,  7, 48,  19, 42, 62,  36, 74, 13,
							 54, 65,  4,  59, 25, 39,  10, 33, 80,
							  1, 51, 71,  45, 56, 22,  77, 16, 30};
unsigned turnNumber = 0;
unsigned minID = 0;
Player* currentPlayer;
Player* p;
