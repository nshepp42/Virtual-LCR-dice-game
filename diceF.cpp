// diceF.cpp 

#include "diceF.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>
using namespace std;


void Dicef::assignScore(const int NUMPLAYERS, int players[]) {
	for (int i = 0; i < NUMPLAYERS; ++i) {
		players[i] = 3;
	}
}
void Dicef::continueRoll(const int PLAYERNUM) {
	char response;
	cout << "Player: " << PLAYERNUM + 1 << ", would you like to roll your dice? Type Y to roll: " << endl;
	cin >> response;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	response = toupper(response);

	while (response != 'Y') {
		cout << "Player did not select Y" << endl;
		cout << "Player: " << PLAYERNUM + 1 << ", would you like to roll your dice? Type Y to roll " << endl;
		cin >> response;
		response = toupper(response);
	}
}
int Dicef::moveandPrint(const int RESULT, const int PLAYERNUM, const int NUMPLAYERS, int center, int players[]) {
	
	if (RESULT == 1) { //left move
		if (PLAYERNUM != 0) {
			--players[PLAYERNUM];
			++players[PLAYERNUM - 1];
			cout << "Player: " << PLAYERNUM + 1 << " rolled L gives one chip to Player: " << PLAYERNUM << endl;
		}
		else {
			--players[PLAYERNUM];
			++players[NUMPLAYERS - 1];
			cout << "Player: " << PLAYERNUM + 1 << " rolled L and gives one chip to Player: " << NUMPLAYERS << endl;
		}
	}
	else if (RESULT == 2) { //right move
		if (PLAYERNUM != NUMPLAYERS - 1) {
			--players[PLAYERNUM];
			++players[PLAYERNUM + 1];
			cout << "Player: " << PLAYERNUM + 1 << " rolled R and gives one chip to Player: " << PLAYERNUM + 2 << endl;
		}
		else {
			--players[PLAYERNUM];
			++players[0];
			cout << "Player: " << PLAYERNUM + 1 << " rolled R and gives one chip to Player: 1" << endl;
		}
	}
	else if (RESULT == 3) { //center move
		--players[PLAYERNUM];
		center = center + 1;
		cout << "Player: " << PLAYERNUM + 1 << " rolled C and gives one chip to the Center pot" << endl;
		
	}
	else {
		cout << "Player: " << PLAYERNUM + 1 << " rolled O and does nothing" << endl;
	}
	cout << endl;
	return center;
}
int Dicef::displayandCheck(const int NUMPLAYERS, int center, int players[]) {
	int zeroscoreCount = 0;
	
	cout << "Current Scores: " << endl;
	cout << "Center: " << center << endl;
	for (int i = 0; i < NUMPLAYERS; ++i) {
		cout << "Player: " << i + 1 << " has " << players[i] << " chips" << endl;
		if (players[i] <= 0) {
			++zeroscoreCount;
		}
	}
	return zeroscoreCount;
}
int Dicef::changeActivePlayer(int playernum, const int NUMPLAYERS) {
	
	if (playernum != 0) {
		playernum = playernum - 1; //player to the left
	}
	else {
		playernum = NUMPLAYERS - 1; //goes from player 1 (players[0]) to the highest player number (NUMPLAYERS - 1)
	}
	return playernum;
}