#pragma once
#pragma once
#include <string>
#include <iostream>
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
	int foursScored = 0;
	int sixesScored = 0;
	int runsScored = 0;
	int ballsBatted = 0;

	//bowler
	int wicketsTaken = 0;
	int ballsBowled = 0;
	int runsGiven = 0;

	Player() {}

	Player(std::string nm, std::string rol, int rns, float sr, int frs, int sxs, int bls, int wkts) {
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

		ballsBowled++;
		int randomNumber = (rand() % 1000);
		if (randomNumber < pWicket) {
			return true;
		}
		return false;
	}

	int bats() {
		int cum0 = pZero;
		int cum1 = cum0 + pOnes;
		int cum4 = cum1 + pFours;
		int cum6 = cum4 + pSixes;

		ballsBatted++;
		int rN = (rand() % cum6);
		if (rN <= cum0) {
			return 0;
		}
		else if (rN <= cum1) {
			return 1;
		}
		else if (rN <= cum4) {
			foursScored++;
			return 4;
		}
		sixesScored++;
		return 6;
	}
};