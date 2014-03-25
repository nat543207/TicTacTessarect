/*
 * Engine.h
 *
 *  Created on: Mar 25, 2014
 *      Author: nat543207
 */

#ifndef ENGINE_H_
#define ENGINE_H_

class Player;

Player* startGame();
void boardSetup();
char gameLoop(Player*);
void endGame();
int* getPlayerMove();


#endif /* ENGINE_H_ */
