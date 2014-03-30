/*
 * Rules.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: nat543207
 *
 *      Contains implementation of Player class and some other bits of code.  Responsible for victory checking, changing
 *      which player is currently active, etc.  May be refactored later to disperse functionality among other, more
 *      specialized classes.
 */

#include <iostream>
#include <fstream>
#include "../headers/Engine.h"
#include "../headers/Rules.h"
#include "../headers/Generalization.h"

bool moveIsValid(int move)
{
	for(int i = 0; i < numberOfPlayers; i++)
	{
		//TODO Get access to currentPlayer array in function.  Probably necessitates a bigration to Rules or passing
		//as an argument.
		for(int j = 0; i < turnNumber; j++)
		{
			if(magicSquare[move] == 0 /*p[j]*/)
			{
				std::cout << "Space is occupied.  Please choose another.";
				return true;
			}
		}
	}
	return false;
}
