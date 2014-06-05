/*
 * Player.h
 *
 *  Created on: Mar 30, 2014
 *      Author: nat543207
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include "UI.h"

class Player
{
	private:
		std::vector<unsigned> occupied;
		char mark;
		Player* nextPlayer;
		unsigned id;
		static UI_Handler ui;
		void addToMoveHistory(const int);
		void recurseThroughMoveList(int, int*&);
		bool cycleThroughMoveArray(const std::vector<int>&);
	public:
		Player();
		virtual ~Player();

		char getMark()					{return this->mark;}
		Player& getNextOpponent()		{return *(this->nextPlayer);}
		unsigned getID()				{return this->id;}
		int operator[](int i) 			{return this->occupied[i];}
		int numberOfMovesMade()			{return this->occupied.size();}
		void setNextPlayer(Player& p)	{this->nextPlayer = &p;}
		void setMark(char a)			{this->mark = a;}
		void setID(int i)		 		{this->id = i;}
		bool wins();
		void makeMove();
};

#endif /* PLAYER_H_ */
