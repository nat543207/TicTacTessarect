/*
 * Player.h
 *
 *  Created on: Mar 30, 2014
 *      Author: nat543207
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

class Player
{
	private:
		std::vector<int> occupied;
		char mark;
		Player* nextPlayer;
		unsigned id;
	public:
		Player();
		virtual ~Player();
		char getMark()				{return this->mark;}
		Player& getNextOpponent()	{return *(this->nextPlayer);}
		unsigned getID()			{return this->id;}
		int operator[](int i) 		{return this->occupied[i];}
		void setOpponent(Player& p)	{this->nextPlayer = &p;}
		void setMark(char a)		{this->mark = a;}
		void setID(int i)		 	{this->id = i;}
		int movesMade();
		bool wins();
		void makeMove();
		void addToMoveHistory(const int);
		void addToBoard(const int);
};

#endif /* PLAYER_H_ */
