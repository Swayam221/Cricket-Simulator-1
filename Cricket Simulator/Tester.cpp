#pragma once
#include "Player.h"
#include <iostream>
#include "Team.h"
using namespace std;

//Player player("Rohit Sharma", "Bat", 4898, 130.82, 431, 194, 0, 0);
Player player("Lasith Malinga", "Ball", 88, 88.88, 6, 5, 2827, 170);

void testPlayer(Player player) {
	cout << player.name << "\t";
	cout << player.role << "\t";
	cout << player.pFours << "\t";
	cout << player.pOnes << "\t";
	cout << player.pSixes << "\t";
	cout << player.pZero << "\t";
	cout << player.pWicket << "\t";
	cout << player.canBall() << "\n";
}

void testTeam(Team team) {
	while (!team.bowling.empty()) {
		testPlayer(team.bowling.front());
		team.bowling.pop();
	}
}

void testTakesWicket(Player player) {
	for (int i = 0; i < 100; i++) {
		cout << player.takesWicket() << "\t";
	}
	cout << "\n";
}

void testBats(Player player) {
	for (int i = 0; i < 100; i++) {
		cout << player.bats() << "\t";
	}
	cout << "\n";
}

int main() {
	srand((unsigned)time(0));
	//testTeam(Team("MI"));
	//testPlayer(player);
	//testTakesWicket(player);
	//testBats(player);

	return 0;
}

