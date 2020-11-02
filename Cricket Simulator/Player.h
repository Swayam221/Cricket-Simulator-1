#pragma once
#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Player
{
	//data from csv
	int totalRuns;
	float strikeRate;
	int fours;
	int sixes;
	int ballsThrown;
	std::string role;
	int wickets;

	//calculated
	int ballsPlayed;
	int ones;

	//probabilities
	float pFours;
	float pSixes;
	float pOnes;
	float pWicket;
	float pZero;

public:
	std::string name;

	//batsman
	int foursScored;
	int sixesScored ;
	int runsScored ;
	int ballsBatted ;

	//bowler
	int wicketsTaken ;
	int ballsBowled ;
	int runsGiven ;

	Player() {}

	Player(std::string nm, std::string rol, int rns, float sr, int frs, int sxs, int bls, int wkts) {
		//batsman
		foursScored = 0;
		sixesScored = 0;
		runsScored = 0;
		ballsBatted = 0;

		//bowler
		wicketsTaken = 0;
		ballsBowled = 0;
		runsGiven = 0;

		name = nm;
		role = rol;
		totalRuns = rns;
		strikeRate = sr;
		fours = frs;
		sixes = sxs;
		ballsThrown = bls;
		wickets = wkts;
		ballsPlayed = totalRuns / (strikeRate / 100);
		pFours = ((fours * 1.0) / ballsPlayed) * 1000;
		pSixes = ((sixes * 1.0) / ballsPlayed) * 1000;
		ones = (totalRuns - (fours * 4) - (sixes * 6));
		pOnes = ((ones * 1.0) / ballsPlayed) * 1000;
		pZero = (((ballsPlayed - fours - sixes - ones) * 1.0) / ballsPlayed) * 1000;
		if (ballsThrown != 0)
		{
			pWicket = (wickets * 1.0 / ballsThrown) * 1000;
		}
	}

	bool canBall() {
		if (role != "Bat") {
			return true;
		}
		return false;
	}

	bool takesWicket() {

		//ballsBowled++;
		int randomNumber = (rand() % 1000);
		if (randomNumber < pWicket) {
			return true;
		}
		return false;
	}

	int bats(int balls) {
		int cum0 = pZero;
		int cum1 = cum0 + pOnes;
		int cum4 = cum1 + pFours;
		int cum6 = cum4 + pSixes;
		//ballsBatted++;
		int rN = (rand() % cum6);

		//powerplay
		if (balls < 30) 
			rN += 75;

		if (rN <= cum0) {
			return 0;
		}
		else if (rN <= cum1) {
			return 1;
		}
		else if (rN <= cum4) {
			//foursScored++;
			return 4;
		}
		//sixesScored++;
		return 6;
	}
};