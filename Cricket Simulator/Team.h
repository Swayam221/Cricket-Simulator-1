#pragma once
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include "Player.h"
using namespace std;

class Team {

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
	int ballsFaced = 0;
	float wins = 0;

	int runsScoredIn1Match = 0;

	Team() {}
	Team(string teamName) {
		name = teamName;
		ifstream teamFile;
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
		runsScoredIn1Match = 0;
	}

	Player getBowler() {
		bowlerInd += 1;
		return bowling.at(bowlerInd % bowling.size());
	}

	Player getBatsman() {
		batsmanInd += 1;
		return batting.at(batsmanInd % batting.size());
	}

	void getAvgResults(int n) {
		runsScored = runsScored / n;
		wicketsLost = wicketsLost / n;
		ballsFaced = ballsFaced / n;
		wins = wins / n;

		for (int i = 0; i < 11; i++) {
			//batsman
			batting[i].foursScored = batting[i].foursScored / n;
			batting[i].sixesScored = batting[i].sixesScored / n;
			batting[i].runsScored = batting[i].runsScored / n;
			batting[i].ballsBatted = batting[i].ballsBatted / n;

			//bowler
			batting[i].wicketsTaken = batting[i].wicketsTaken / n;
			batting[i].ballsBowled = batting[i].ballsBowled / n;
			batting[i].runsGiven = batting[i].runsGiven / n;
		}
	}
	int getAvgRunsScored(int n)
	{
		runsScored = runsScored / n;
		return runsScored;
	}
};
