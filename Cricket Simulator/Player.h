#pragma once
#include <string>
#include <iostream>
#include <time.h>

class Player
{
	int totalRuns;
	float strikeRate;
	int fours;
	int sixes;
	int ballsThrown;
	int ballsPlayed;
	int wickets;
	int ones;
public:
	std::string name;
	std::string role;
	float pFours;
	float pSixes;
	float pOnes;
	float pWicket;
	float pZero;
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
		pFours = ((fours * 1.0) / ballsPlayed)*1000;
		pSixes = ((sixes * 1.0) / ballsPlayed) * 1000;
		ones = (totalRuns - (fours * 4) - (sixes * 6));
		pOnes = ((ones * 1.0) / ballsPlayed) * 1000;
		pZero = (((ballsPlayed - fours - sixes- ones)*1.0)/ballsPlayed) * 1000;
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
		int randomNumber = (rand() % 1000) ;
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

		int rN = (rand() % cum6);
		if (rN < cum0) {
			return 0;
		}
		else if (rN < cum1) {
			return 1;
		}
		else if (rN < cum4) {
			return 4;
		}
		return 6;
	}
};