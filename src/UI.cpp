/*
 * UI.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: nat543207
 */

#pragma GCC diagnostic ignored "-Wsign-compare" //I know what I'm doing with unsigneds, but thanks.
#include "../headers/Generalization.h"
#include <iostream>
#include "math.h"
#include <limits>

std::string UI_Handler::board_components[2][2] = 	{{" _ |", "---+"},
													 {" _  ", "--- "}};

std::string UI_Handler::board;

int numberOfColumnsOfBoards, numberOfRowsOfBoards, numberOfRowsPerBoard, lengthOfBoardArray;


void UI_Handler::text_printBoard()
{
	std::cout << board;
}

int UI_Handler::text_getMove()
{
	int input[dimensions];
	int move = 1;

//	do
	{
		this->clearInputStream(std::cin);
		for(int i = dimensions - 1; 0 <= i; i--)
		{
			std::cout << "Enter coordinates of move for dimension " << i + 1 << std::endl;
			int buffer;
			for(bool inputSuccess = false; !inputSuccess;)
			{
				//TODO Sanitize input!!!
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

//		for(int i = 1; i <= 9; i++)
//			text_addToBoard(i);

//		move = 1 + (input[0]) + (input[1] - 1)*pow(sideLength, (numberOfColumnsOfBoards - 1)) + (input[2] - 1) * sideLength + (input[3] - 1)*pow(sideLength, (numberOfRowsOfBoards));

		for(int i = 0; i < dimensions; i++)
		{
			if(i % 2)
				move += (input[i] - 1) * pow(sideLength, i/*ceil(i / 2.0)*/); //fix
			else
				move += (input[i] - 1) * pow(sideLength, ceil(i / 2.0)/* + (i - 1)*/);
		}
	}
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

/*
 * Calculates which character in the array ought to be replaced with the player's mark.
 * Fully functional, DO NOT EDIT!
 */
void UI_Handler::text_addToBoard(int move)
{
	double cellsPerRow = pow(sideLength, ceil(dimensions / 2.0)); //What does it mean?  I don't know, but it works.
	int boardPos = ceil((ceil(move / cellsPerRow) / (double) sideLength)) + 4 * ((move - 1) //aligns mark placement to center of 'cell'
			+ cellsPerRow * (ceil(move /  cellsPerRow) //causes program to skip over the lines that are filled with '-' and '+'
					- ceil(move / (double) (sideLength * cellsPerRow)))); //makes the top row of moves align to top row of board on rows of boards after the first

	board[boardPos] = currentPlayer->getMark();
}

/*
 * Constructs the board from the items in boardComponents array, defined at top of file.
 */
void UI_Handler::text_buildBoard(int sideLength, int dimensions)
{
	bool isGraphicalBreak = false;

	numberOfColumnsOfBoards = pow(sideLength, ceil(dimensions / 2.0) - 1);
	numberOfRowsOfBoards = pow(sideLength, floor(dimensions / 2.0) - 1);
	numberOfRowsPerBoard = 2 * sideLength;
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
}

/*
 * Throws out the next 256 characters from cin.  If there are more than that, the user shouldn't be allowed
 * to use the program.
 */
void UI_Handler::clearInputStream(std::istream &stream)
{
	char* trash[256];
	stream.readsome(*trash, 256);
}
