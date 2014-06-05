/*
 * Player.cpp
 *
 *  Created on: Mar 30, 2014
 *      Author: nat543207
 *
 * A class that stores a single player's information, including what moves they've made, their mark
 * on the board, etc.
 */

#pragma GCC diagnostic ignored "-Wsign-compare" //I know what I'm doing with unsigneds, but thanks.
#include "../headers/Player.h"
#include "../headers/Generalization.h"
#include "../headers/Engine.h"
#include "../headers/UI.h"
#include <iostream>
#include <cmath>


UI_Handler Player::ui;

Player::Player() : mark('\0'), nextPlayer(this), id(0)
{
	occupied.resize(1); //Stops the program from segfaulting on operator[]() call
};

Player::~Player()
{

}

/*
 * Calculates a factorial.
 */
int factorial(int number)
{
	int result = 1;

	for(int i = 1; i <= number; i++)
		result *= i;

	return result;
}

/*
 * Calculate the number of combinations of r objects from a pool of n objects there are.
 */
int nCr(int n, int r)
{
	return factorial(n) / (factorial(n - r) * factorial(r));
}

/*
 * Moves you to the next combination of values to sum.
 */
void decrementPositionInArray(int* &array, int index)
{
	array[index]--;
	if(array[index] == 0)
	{
		decrementPositionInArray(array, index - 1);
		array[index] = array[index - 1] - 1;
	}

	//Code in progress, not yet functional
//	array[index]--;
//	if(array[index] == array[index + 1])
//	{
//		incrementPositionInArray(array, index - 1);
//		array[index] = array[index - 1] - 1;
//	}

}

/*
 * Tells you if the current player has won by summing each value in his/her move
 * list sequentially, so that it can be determined if the magic sum has been
 * attained.
 */
bool Player::wins()
{
		int* indices = new int[sideLength + 1];
		for(int i = 0, j = occupied.size(); i <= occupied.size(); i++, j--)
			indices[i] = j;

		for(int i = nCr(occupied.size(), dimensions); 0 < i; i--)
		{
			int sum = 0;

			for(int j = 0; j <= dimensions; j++)
				sum += occupied[j];

			if(sum == magicSum)
			{
				delete[] indices;
				return true; //TODO
			}

			decrementPositionInArray(indices, dimensions - 1);
		}


		delete[] indices;
		return false;
}

/*
 * Encapsulation of addToMoveHistory() and text_addToBoard()
 */
void Player::makeMove()
{
	int move = ui.text_getMove();
	this->addToMoveHistory(move - 1);
	ui.text_addToBoard(move);
	ui.text_printBoard();
}

/*
 * Adds the value of the magic n-square at the provided board index to the player's
 * list of moves, which is used for checking victory and occupation.
 */
void Player::addToMoveHistory(const int move)
{
	unsigned* ptr = &magicArray[0];
	this->occupied.push_back(*(ptr + move));
}
