#pragma once
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include "Player.h"
using namespace std;

class Team {

	ifstream teamFile;
	string line;
	string playerName;
	string role;
	int playerRuns;
	float strikeRate;
	int fours;
	int sixes;
	int balls;
	int wickets;
	string temp;

	

public:
	string name;
	int bowlerInd = -1;
	int batsmanInd = -1;
	vector <Player> batting;
	vector <Player> bowling;

	int runsScored = 0;
	int wicketsLost = 0;

	Team() {}
	Team(string teamName) {
		name = teamName;
		teamFile.open(teamName + ".csv");

		getline(teamFile, line, '\n');

		while (getline(teamFile, line)) {
			stringstream ss(line);
			getline(ss, playerName, ',');
			getline(ss, role, ',');
			getline(ss, temp, ',');
			stringstream temp2(temp);
			temp2 >> playerRuns;

			getline(ss, temp, ',');
			stringstream temp3(temp);
			temp3 >> strikeRate;

			getline(ss, temp, ',');
			stringstream temp4(temp);
			temp4 >> fours;

			getline(ss, temp, ',');
			stringstream temp5(temp);
			temp5 >> sixes;

			getline(ss, temp, ',');
			stringstream temp6(temp);
			temp6 >> balls;

			getline(ss, temp, ',');
			stringstream temp7(temp);
			temp7 >> wickets;

			Player player(playerName, role, playerRuns, strikeRate, fours, sixes, balls, wickets);
			batting.push_back(player);
			if (player.canBall()) { bowling.push_back(player); }
		}


		teamFile.close();
	}

	void reset() {
		bowlerInd = -1;
		batsmanInd = -1;
	}

	Player getBowler() {
		bowlerInd += 1;
		return bowling.at(bowlerInd % bowling.size());
	}

	Player getBatsman() {
		batsmanInd += 1;
		return batting.at(batsmanInd % batting.size());
	}
};