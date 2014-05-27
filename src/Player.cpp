/*
 * Player.cpp
 *
 *  Created on: Mar 30, 2014
 *      Author: nat543207
 */

#pragma GCC diagnostic ignored "-Wsign-compare" //I know what I'm doing with unsigneds, but thanks.
#include "../headers/Player.h"
#include "../headers/Generalization.h"
#include "../headers/Engine.h"
#include "../headers/Rules.h"
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

void Player::recurseThroughMoveList(int number, int* &values)
{
	for(int i = sideLength - number; i < this->occupied.size() - number; i++)
	{
		recurseThroughMoveList(number - 1, values);
		values[i] = this->occupied[i];
	}
}

int factorial(int number)
{
	int result = 1;

	for(int i = 1; i <= number; i++)
		result *= i;

	return result;
}

int nCr(int n, int r)
{
	return factorial(n) / (factorial(n - r) * factorial(r));
}

void incrementPositionInArray(int* &index, int indexToIncrement)
{
	index[indexToIncrement]--;
	if(index[indexToIncrement] == 0)
	{
		incrementPositionInArray(index, indexToIncrement - 1);
		index[indexToIncrement] = index[indexToIncrement - 1] - 1;
	}
}

/*
 * REWRITE TO ACCOMODATE SIDE LENGTHS OTHER THAN THREE!
 *
 * Tells you if the current player has won by summing each value in his/her move
 * list sequentially, so that it can be determined if the magic sum has been
 * attained.
 */
bool Player::wins()
{
	int* indices = new int[sideLength];

		for(int i = 1; i <= sideLength; i++)
			indices[i - 1] = this->occupied.size() - i;

		for(int j = 0; j < nCr(this->occupied.size() - 1, sideLength); j++)
		{
			int sum = 0;

			for(int k = 0; k < sideLength; k++)
			{
				std::cout << occupied[indices[k]];
				sum += occupied[indices[k]];
			}

			std::cout << '\n';

			if(sum == magicSum)
				return true;

			incrementPositionInArray(indices, sideLength - 2);
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
	unsigned* ptr = &magicTessarect[0];
	this->occupied.push_back(*(ptr + move));
}
