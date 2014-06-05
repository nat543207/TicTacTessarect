/*
 * UI.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: nat543207
 *
 * Various methods that allow players to interface with the program, as well as the board generation methods.
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

/*
 * Gets a user's coordinate input and converts it into a board index to be used
 * by text_addToBoard()
 */
int UI_Handler::text_getMove()
{
	int input[dimensions];
	int move = 1;

//	do
	{
		for(int i = dimensions - 1; 0 <= i; i--)
		{
			if(!input[i])
				std::cout << "Enter coordinates of move for dimension " << i + 1 << std::endl;
			int buffer = 0;
			for(bool inputSuccess = false; !inputSuccess;)
			{
				std::cin >> buffer;
				if(dimensions % 2)
				{
					if(buffer < 1 || sideLength < buffer) //needs to be more robust, scaling with increased numberOfRowsOfBoards
					{
						std::cout << "Invalid coordinates, please re-enter.\n";
						continue;
					}
				}
				else
				{

				}
				inputSuccess = true;
			}
			input[i] = buffer;
		}

		for(int i = 0; i < dimensions; i++)
		{
			if(dimensions % 2)
			{
				if(i % 2)
					move += (input[i] - 1) * pow(sideLength, floor(dimensions / 2.0) + ceil(i / 2.0)); //last term is added to the value of ceil, scales like dimensions.  Don't know quite how yet, though
				else
					move += (input[i] - 1) * pow(sideLength, i / 2.0);

			}
			else
			{
				if(i % 2)
					move += (input[i] - 1) * pow(sideLength, floor(dimensions / 2.0) + ceil(i / 2.0) - 1); //last term is added to the value of ceil, scales like dimensions.  Don't know quite how yet, though
				else
					move += (input[i] - 1) * pow(sideLength, i / 2.0);
			}
		}
	}
//	while(!text_moveIsValid(move));

	return move;
}

/*
 * Checks to see if a given move is legal, e. g. if all the given coordinate values
 * are less than the maximum values for their dimensions, if the position is already occupied, etc.
 */
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
