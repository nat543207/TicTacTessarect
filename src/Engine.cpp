/*
 * main.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: nat543207
 */
#include <iostream>
#include <string>
#include "../headers/Engine.h"
#include "../headers/Rules.h"
#include "../headers/Generalization.h"


int main()
{
//	configure();
	Player* p = startGame();
	std::cout << gameLoop(&p[0]) << " wins!";
}

void configure()
{
	//Dead code.

	//TODO Implement some method of assigning the "Generalization" variables via user input.

//	int storage;
//	std::cout << "How many people are playing?" << std::endl;
//	std::cin >> storage;
//	players = storage;
//	std::cout << "How many cells would you like in each row, column, and diagonal?" << std::endl;
//	std::cin >> storage;
//	sideLength = storage;
//	std::cout << "How many dimensions would you like the board to span?" << std::endl;
//	std::cin >> storage;
//	dimensions = storage;
//	magicSum = (sideLength * (sideLength * sideLength + 1)) / 2;
}

/*
 * Generates the array of Players who are playing the game
 */
Player* startGame()
{
	Player* p = new Player[numberOfPlayers];
	for(unsigned i = 0; i < numberOfPlayers; i++)
	{
		//Initializer loop for each Player's instance variables
		std::cout << "Player " << i + 1 << ", please enter the symbol that will mark your moves:" << std::endl;
		char a;
		std::cin >> a;
		p[i].setMark(a);
		p[i].setOpponent(p[(i + 1) % numberOfPlayers]);
		p[i].setID(minID + i);
	}
	return p;
}

void boardSetup()
{
	//TODO Write this function.
	//TODO Implement some method of generating board for n dimensions.  For now, using template in resources folder.
//	std::fstream file;
//	file.open("../resources/board");

}

char gameLoop(Player* currentPlayer)
{
	do
	{
		if(currentPlayer->getID() == minID)
			turnNumber++;
		std::cout << "Player " << currentPlayer->getMark() << " to move." << std::endl;
		currentPlayer->makeMove(getPlayerMove());
		currentPlayer = &(currentPlayer->getOpponent());
	}
	while(!currentPlayer->getOpponent().wins());

	return currentPlayer->getOpponent().getMark();
}

void endGame()
{

}

int* getPlayerMove()
{
	int* input = new int[dimensions];

//	do
//	{
		for(int i = dimensions - 1; 0 <= i; i--)
		{
			std::cout << "Enter coordinates of move for dimension " << i << std::endl;
			std::cin >> input[i];
		}
//	}
	//TODO Fix this.  Need to redefine or restructure spaceOccupied to get it to work.
//	while(spaceOccupied());

	std::cout << "Move received." << std::endl;
	return input;
}
