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
#include "../headers/UI.h"

const int tempHack = 2; //Just to make it compile
Player p[tempHack];  //Will eventually be p[numberOfPlayers], but the compiler doesn't like that right now.

int main()
{
	currentPlayer = &p[0];

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

	do
	{
		if(currentPlayer->getID() == minID)
			turnNumber++;
		std::cout << "Player " << currentPlayer->getMark() << " to move." << std::endl;
		currentPlayer->makeMove();
		currentPlayer = &(currentPlayer->getNextOpponent());
	}
	while(!currentPlayer->getNextOpponent().wins());

	currentPlayer = &p[(currentPlayer->getID() + numberOfPlayers - 1) % (numberOfPlayers + 1)];
	std::cout << currentPlayer->getMark() << " wins!" << std::endl;
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
