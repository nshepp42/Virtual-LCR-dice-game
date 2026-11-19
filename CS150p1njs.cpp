// CS150p1njs.cpp : Nicolas Sheppard

#include "diceF.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {	
	
	srand(unsigned(time(NULL)));
	int numplayers;
	bool continuegame = true;
	int playernum = 0; //starts at player 1 or pos 0 in the players[] array
	int players[10];
	int result;
	int center = 0;
	Dicef dice; //Dicef object

	cout << "Welcome to LRC! (it's actually LCR but it's easier to organize with LRC haha)" << endl;
	cout << "Please enter 3-10 players: ";
	cin >> numplayers;
	while (numplayers < 3 || numplayers > 10) {
		cout << "Invalid number of players" << endl << "Enter 3-10 players: ";
		cin >> numplayers;
	}
	cout << endl;
	
	dice.assignScore(numplayers, players); //gives everyone 3 chips
	dice.continueRoll(playernum);

	while (continuegame == true) { //beginning of main while loop
		int chips = players[playernum];
		int rolls;
		if (chips >= 3) {
			rolls = 3;
		}
		else if (chips <= 0) {
			cout << "Sorry, but you have no chips and cannot roll any dice!" << endl;
			rolls = 0;
		}
		else {
			rolls = chips;
		}
		cout << "Rolling dice"; //Awesome animation!!
		for (int i = 0; i < rolls; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(700));
			cout.flush();
			cout << ". ";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
		cout << endl << endl;

		while (rolls > 0) { //roll all dice
			result = (rand() % 6) + 1;
			center = dice.moveandPrint(result, playernum, numplayers, center, players);

			rolls = rolls - 1;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));

		int scoresbelow0 = dice.displayandCheck(numplayers, center, players);
		if (scoresbelow0 < numplayers - 1) {
			playernum = dice.changeActivePlayer(playernum, numplayers);
			dice.continueRoll(playernum);
			continuegame = true;
		}
		else { //runs if someone won the game
			for (int i = 0; i < numplayers; ++i) {
				if (players[i] >= 1) {
					cout << "Player: " << i+1 << " wins " << center << " chips!" << endl << "Game over" << endl;
					continuegame = false;
				}
			}
		}

	}

return 0;
}