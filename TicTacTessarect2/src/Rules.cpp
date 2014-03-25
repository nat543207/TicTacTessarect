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
#include "../headers/Rules.h"
#include "../headers/Generalization.h"

Player::Player() : mark('\0'), opponent(this), id(0) {};

//Player::Player(char mark) : mark(mark), opponent(this) {}

//Player::Player(char mark, Player& opponent) : mark(mark), opponent(&opponent) {}

char Player::getMark()
{
	return this->mark;
}

Player& Player::getOpponent()
{
	return *(this->opponent);
}

int Player::getID()
{
	return this->id;
}

int Player::movesMade()
{
	return this->occupied.size();
}

bool Player::wins()
{
	for(int i = 0; i < this->occupied.size(); i++)
	{
		std::cout << this->occupied[i] << " ";
	}
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
	//				else if(p.occupied[first] == p.occupied[second] && p.occupied[second] == p.occupied[third])
	//					return true;
				}
			}
		}
	}
	return false;
}

void Player::setOpponent(Player& p)
{
	this->opponent = &p;
}

void Player::setMark(char c)
{
	this->mark = c;
}

void Player::setID(int id)
{
	this->id = id;
}

int Player::operator[](int i)
{
	return this->occupied[i];
}


bool spaceOccupied(int move, Player p)
{
	for(int i = 0; i < turnNumber; i++)
	{
		if(magicSquare[move] == p[i])
		{
			std::cout << "Space is occupied.  Please choose another.";
			return false;
		}
		//TODO Fix the 'i < 0' statement above, make it  'i < the length of the player's move array'
	}
	return true;
}


void Player::makeMove(int* move)
{
	//TODO Sanitize input!!!
	int moveInArray = 1;
	for(int i = dimensions - 1; 0 < i; i--)
		moveInArray *= (move[i] - 1) * sideLength;
	moveInArray += (move[0] - 1);

	this->addToMoveHistory(moveInArray);
//	this->addToBoard(moveInArray);
	delete move;
}

void Player::addToMoveHistory(const int move)
{
	unsigned* ptr = &magicSquare[0];
	this->occupied.push_back(*(ptr + move));
}

void Player::addToBoard(const int move)
{
	std::fstream board;
	board.open("../resources/board.default");
	const char* file = "../resources/board.default";
	const char* mode = "r";
	int j = 0;
	for(int i = 0; i < move; j++)
	{
		//TODO Get each character sequentially (may skip whitespace), count the number of delimiter ('?') characters
		if(std::fgetc(fopen(file, mode)) == '?')
			i++;
	}
	//TODO Assign character in position the mark of the current player
}
