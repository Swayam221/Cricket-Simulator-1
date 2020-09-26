#pragma once
#include "Player.h"
#include <iostream>
#include "Team.h"
#include "Match.h"
using namespace std;

//Player player("Rohit Sharma", "Bat", 4898, 130.82, 431, 194, 0, 0);
//Player player("Lasith Malinga", "Ball", 88, 88.88, 6, 5, 2827, 170);

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

void testMatch() {
	Team mi("MI");
	Team csk("CSK");
	Team* mip = &mi;
	Team* cskp = &csk;
	Match match1(mip, cskp);
	match1.play();
	cout << match1.team1->runsScored << "\n";
	cout << match1.team2->runsScored << "\n";
	cout << match1.team1->wicketsLost << "\n";
	cout << match1.team2->wicketsLost << "\n";

	Match match2(cskp, mip);
	match2.play();
	cout << match2.team1->runsScored << "\n";
	cout << match2.team2->runsScored << "\n";
	cout << match2.team1->wicketsLost << "\n";
	cout << match2.team2->wicketsLost << "\n";
}

int main() {
	srand((unsigned)time(0));
	//testTeam(Team("MI"));
	//testPlayer(player);
	//testTakesWicket(player);
	//testBats(player);
	testMatch();

	return 0;
}