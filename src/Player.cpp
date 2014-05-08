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

/*
 * Guess.
 */
bool Player::wins()
{
	if(sideLength <= this->occupied.size())
	{
		for(unsigned first = 0; first < this->occupied.size() - 2; first++)
		{
			for(unsigned second = first + 1; second < this->occupied.size() - 1; second++)
			{
				for(unsigned third = second + 1; third < this->occupied.size(); third++)
				{
					if((this->occupied[first] + this->occupied[second] + this->occupied[third]) == magicSum)
					{
						//If a player has moves in their array that sum to the magic number...
						std::cout << "Player " << this->mark << " wins!";
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Player::makeMove()
{
//	int move = ui.text_getMove();
//	this->addToMoveHistory(moveInArray);
	for(int move = 1; move <= std::pow(sideLength, dimensions); move++)
		ui.text_addToBoard(move);
	ui.text_printBoard();
}

void Player::addToMoveHistory(const int move)
{
	unsigned* ptr = &magicSquare[0];
	this->occupied.push_back(*(ptr + move));
}
