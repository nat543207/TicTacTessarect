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
		Player* opponent;
		int id;
	public:
		Player();
		virtual ~Player();
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

#endif /* PLAYER_H_ */
