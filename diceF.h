// diceF.h : Nicolas Sheppard

#ifndef DICEF_H
#define DICEF_H

#include <iostream>
#include <string>
using namespace std;

class Dicef {
private:
	int players[10];
	int numplayers;
	int playernum;

public:

	void assignScore(const int NUMPLAYERS, int players[]); //assigns each player 3 (only once per game) will not be in while loop but after numplayers if established
	
	int moveandPrint(const int RESULT, const int PLAYERNUM, const int NUMPLAYERS,int center, int players[]); //moves chips or deletes chips accordingly or does nothing if 
	
	int displayandCheck(const int NUMPLAYERS, int center, int players[]); //checks scores and returns number of player scores below 0
	
	void continueRoll(const int PLAYERNUM); //asks if next player would like to start their roll until they say yes, while loop returns to the top (once before while loop, one inside while loop) 

	int changeActivePlayer(int playernum, const int NUMPLAYERS); //changes the current player. Clockwise rotations.


};


#endif