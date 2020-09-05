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
	queue <Player> batting;
	queue <Player> balling;

	Team(string teamName) {
		name = teamName;
		teamFile.open(teamName + ".csv" );

		getline(teamFile, line, '\n');

		while (getline(teamFile, line)) {
			stringstream ss(line);
			getline(ss, playerName, ',');
			getline(ss, role, ',');
			getline(ss, temp, ',');  
			stringstream temp2(temp);
			temp2 >> playerRuns;

			getline(ss, temp, ',');
			stringstream temp2(temp);
			temp2 >> strikeRate;

			getline(ss, temp, ',');
			stringstream temp2(temp);
			temp2 >> fours;

			getline(ss, temp, ',');
			stringstream temp2(temp);
			temp2 >> sixes;

			getline(ss, temp, ',');
			stringstream temp2(temp);
			temp2 >> balls;

			getline(ss, temp, ',');
			stringstream temp2(temp);
			temp2 >> wickets;

			Player player(playerName, role, playerRuns, strikeRate, fours, sixes, balls, wickets);
			batting.push(player);
			if (player.canBall()) { balling.push(player); }
		}


		teamFile.close();
	}
};

