/*
 * Engine.h
 *
 *  Created on: Mar 25, 2014
 *      Author: nat543207
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include "../headers/Player.h"
//class Player;

Player* startGame();
void boardSetup();
char gameLoop(Player*);
void endGame();
int* text_getMoveCoordinates();


#endif /* ENGINE_H_ */
