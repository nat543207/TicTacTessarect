/*
 * UI.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: nat543207
 */

#pragma GCC diagnostic ignored "-Wsign-compare" //I know what I'm doing with unsigneds, but thanks.
#include "../headers/Generalization.h"
#include <iostream>
#include <cmath>
#include <limits>


//char UI_Handler::board[] =					  "  _ | _ | _ "
//											  " ---+---+---"
//											  "  _ | _ | _ "
//											  " ---+---+---"
//											  "  _ | _ | _ ";

std::string UI_Handler::board_components[2][2] = 	{{" _ |", "---+"},
													 {" _  ", "--- "}};

std::string UI_Handler::board ;//= text_boardBuilder(sideLength, dimensions);


void UI_Handler::text_printBoard()
{
//	for(int i = 0; i < sideLength * )
//	std::cout << '1';
//	for(int i = 0, rowNumber = 2; i < board.length(); i++)
//	{
//		if(board[i - 1] == '\n')
//			std::cout << rowNumber++ << " ";
//		std::cout << board[i];
//	}
	std::cout << board;
//	for(int j = 0; j < (2 * sideLength - 1) /*vertical height of the board*/; j++)
//	{
//		for(int k = 1; k <= 4 * sideLength  /*each cell is 4 characters long*/; k++)
//		{
//			std::cout << board[4 * sideLength * j + k]; //prints every character in row
//		}
//
//		std::cout << std::endl;
//	}
}

int UI_Handler::text_getMove()
{
	int input[dimensions];

	for(int i = dimensions - 1; 0 <= i; i--)
	{
		std::cout << "Enter coordinates of move for dimension " << i + 1 << std::endl;
		int buffer;
		for(bool inputSuccess = false; !inputSuccess;)
		{
			this->clearInputStream(std::cin);
			std::cin >> buffer;
			if(buffer < 1 || sideLength < buffer) //needs to be more robust, scaling with increased numberOfRowsOfBoards
			{
				std::cout << "Invalid space.  Please select a valid space.\n";
				continue;
			}
			inputSuccess = true;
		}
		input[i] = buffer;
	}

	int move = 0;

//	do
//	{
		//TODO Sanitize input!!!
		for(int i = dimensions - 1; 1<= i; i--)
			move += ((input[i]) * std::pow(sideLength, i - 2) * std::pow(2, i)) - 1;
//		move += input[0];
//	}
//	while(!text_moveIsValid(move));

	return move;
}

bool UI_Handler::text_moveIsValid(int move)
{
	for(unsigned i = 0; i < numberOfPlayers; i++)
	{
		for(unsigned j = 1; j <= turnNumber; j++)
		{
			if(magicSquare[move] == (p[i % numberOfPlayers])[j])
			{
				std::cout << "Space is occupied.  Please choose another.\n" << std::endl;
				return false;
			}
		}
	}
	return true;
}

void UI_Handler::text_addToBoard(int move)
{
	/*
	 * Calculates which character in the array ought to be replaced with the player's mark.
	 * The complex math causes it to wrap around even-numbered lines, which contain only '-' and '+'
	 * and are only included for the players' benefit.
	 */
	board[std::ceil((std::ceil(move / std::pow(sideLength, std::ceil(dimensions / 2.0))) / (sideLength + 1)))
		   + 4
		   * ((move - 1) //aligns mark placement to center of 'cell'
	  	      + (std::pow(sideLength, std::ceil(dimensions / 2.0)) * (std::ceil(move / pow(sideLength, dimensions - 1)) - 1)) //number of rows of graphical separators
	     )] = currentPlayer->getMark();
}

/*
 * DO NOT ENTER.  This method works, and that's all I really care to know at this point.
 */
void UI_Handler::text_buildBoard(int sideLength, int dimensions)
{
	bool isGraphicalBreak = false;

	int numberOfColumnsOfBoards = std::pow(sideLength, std::ceil(dimensions / 2.0) - 1),
			numberOfRowsOfBoards = std::pow(sideLength, std::floor(dimensions / 2.0) - 1),
			numberOfRowsPerBoard = 2 * sideLength/* - 1*/,
			lengthOfBoardArray = numberOfRowsOfBoards * (numberOfRowsPerBoard + 1) - 1;

	std::string intermediateBoard[lengthOfBoardArray];

	/*
	 * Generates a 2-d board, which the following loops should be able to multiplex into
	 * the necessary matrix of 2-d boards to represent the n-dimensional board.
	 */
	for(int i = 0; i < numberOfRowsPerBoard - 1; i++)
	{
		for(int j = 0; j < sideLength - 1; j++)
		{
			intermediateBoard[i].append(board_components[0][isGraphicalBreak]);
		}

		intermediateBoard[i].append(board_components[1][isGraphicalBreak]);
		isGraphicalBreak = !isGraphicalBreak;
	}

	/*
	 * Multiplexes the single board generated above into a single row of boards, which constitutes the top row of the
	 * play area.
	 */
		for(int i = 0; i < numberOfRowsPerBoard; i++)
		{
			std::string toClone = intermediateBoard[i];

				for(int k = 0; k < numberOfColumnsOfBoards - 1; k++)
					intermediateBoard[i].append(toClone);
				(intermediateBoard[i])[intermediateBoard[i].length() - 1] = '\n';
		}
		intermediateBoard[numberOfRowsPerBoard - 1].append("\n");

		/*
		 * Multiplexes the single row of boards generated above into a square of boards if necessary.
		 */
		for(int i = 0; i < lengthOfBoardArray; i++)
		{
			intermediateBoard[i] = intermediateBoard[i % (numberOfRowsPerBoard + 1)]; //uses only the first (numberOfRowsPerBoard + 1) strings as source, which is what was filled in the above set of loops
		}

	for(int i = 0; i < lengthOfBoardArray; i++)
		board.append(intermediateBoard[i]);
//	board.append("\n");

//	return finalBoard;
}

void UI_Handler::clearInputStream(std::istream &stream)
{
//	stream.clear();
//	stream.ignore(std::numeric_limits<std::streamsize>::max()); //Thank you, StackExchange and Yahoo Answers
	char* trash[256];
	stream.readsome(*trash, 256);
}
