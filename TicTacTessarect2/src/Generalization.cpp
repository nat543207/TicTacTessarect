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


extern const unsigned dimensions = 2;
extern const unsigned sideLength = 3;
extern const unsigned magicSum = 15;
extern const unsigned numberOfPlayers = 2;
extern unsigned magicSquare[9] = {2, 7, 6,
								  9, 5, 1,
								  4, 3, 8};
extern unsigned turnNumber = 0;
extern unsigned minID = 0;
