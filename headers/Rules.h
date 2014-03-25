/*
 * Gameplay.h
 *
 *  Created on: Mar 3, 2014
 *      Author: nat543207
 */

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <vector>

class Player
{
	private:
		std::vector<int> occupied;
		char mark;
		Player* opponent;
		int id;
	public:
		Player();
		Player(char);
		Player(char, Player&);
		char getMark();
		Player& getOpponent();
		int getID();
		int movesMade();
		bool wins();
		void setOpponent(Player&);
		void setMark(char);
		int operator[](int);
		void makeMove(int*);
		void addToMoveHistory(const int);
		void addToBoard(const int);
		void setID(int);
};

bool spaceOccupied(int, Player);

#endif /* GAMEPLAY_H_ */
