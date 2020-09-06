#pragma once
#include "Player.h"
#include <iostream>
#include "Team.h"
using namespace std;

//Player player("Rohit Sharma", "Bat", 4898, 130.82, 431, 194, 0, 0);

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
	while (!team.balling.empty()) {
		testPlayer(team.balling.front());
		team.balling.pop();
	}
}

int main() {
	testTeam(Team("MI"));
	//testPlayer(player);

	return 0;
}

