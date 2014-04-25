/*
 * Player.cpp
 *
 *  Created on: Mar 30, 2014
 *      Author: nat543207
 */

#include "../headers/Player.h"
#include "../headers/Generalization.h"
#include "../headers/Engine.h"
#include "../headers/Rules.h"
#include <iostream>

Player::Player() : mark('\0'), nextPlayer(this), id(0)
{
	occupied.push_back(0); //Stops the program from segfaulting on operator[]() call
};

Player::~Player()
{
	// TODO Auto-generated destructor stub
}

int Player::movesMade()
{
	return this->occupied.size();
}

bool Player::wins()
{
	for(int i = 0; i < this->occupied.size(); i++)
		std::cout << this->occupied[i] << " ";
	std::cout << std::endl;

	if(sideLength <= this->occupied.size())
	{
		for(unsigned first = 0; first < this->occupied.size() - 2; first++)
		{
			for(unsigned second = first + 1; second < this->occupied.size() - 1; second++)
			{
				for(unsigned third = second + 1; third < this->occupied.size(); third++)
				{
//					std::cout << this->occupied[first] << this->occupied[second] << this->occupied[third] << std::endl;
					if((this->occupied[first] + this->occupied[second] + this->occupied[third]) == magicSum)
						return true;
				}
			}
		}
	}
	return false;
}

void Player::makeMove()
{
	int moveInArray = 1;

	do
	{
		int* move = getMoveCoordinates();
		//TODO Sanitize input!!!
		for(int i = dimensions - 1; 0 < i; i--)
			moveInArray *= (move[i] - 1) * sideLength;
		moveInArray += (move[0] - 1);
	}
	while(!moveIsValid(moveInArray));

	this->addToMoveHistory(moveInArray);
//	this->addToBoard(moveInArray);
}

void Player::addToMoveHistory(const int move)
{
	unsigned* ptr = &magicSquare[0];
	this->occupied.push_back(*(ptr + move));
}
