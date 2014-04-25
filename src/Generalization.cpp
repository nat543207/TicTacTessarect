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

extern const unsigned dimensions = 2;
extern const unsigned sideLength = 3;
extern const unsigned magicSum = 15;
unsigned numberOfPlayers = 2;
unsigned magicSquare[9] = {2, 7, 6,
						   9, 5, 1,
						   4, 3, 8};
unsigned turnNumber = 0;
unsigned minID = 0;
Player* currentPlayer;
