/*
 * UI.h
 *
 *  Created on: Apr 15, 2014
 *      Author: nat543207
 */

#ifndef UI_H_
#define UI_H_

#include <iostream>

class UI_Handler
{
	private:
		static std::string board;
		static std::string board_components[2][2];
	public:
		UI_Handler() {}
		virtual ~UI_Handler() {}
		void text_printBoard() {std::cout << board;};
		int text_getMove();
		bool text_moveIsValid(int);
		void text_addToBoard(int);
		void text_buildBoard(int, int);
		static void clearInputStream(std::istream&);
		template <class T> static T getInputOfType()
		{
				std::istream stream;
				T var;
				stream >> var;
				return var;
		}

};

#endif /* UI_H_ */
