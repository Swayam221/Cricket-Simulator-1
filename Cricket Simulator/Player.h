# include <string.h>
# include <stdio.h>
# include <math.h>
class Player
{
	int totalRuns;
	float strikeRate;
	int fours;
	int sixes;
	int balls;
	int ballsPlayed;
	int wickets;
	int ones;
public:
	char name[50];
	char role[10];
	float pFours;
	float pSixes;
	float pOnes;
	float pWicket;
	float pZero;
	Player(char nm[], char rol[], int rns, float sr, int frs, int sxs, int bls, int wkts) {
		strcpy_s(name, 50, nm);
		strcpy_s(role, 10, rol);
		totalRuns = rns;
		strikeRate = sr;
		fours = frs;
		sixes = sxs;
		balls = bls;
		wickets = wkts;
		ballsPlayed = totalRuns / (strikeRate / 100);
		pFours = (fours * 1.0) / ballsPlayed;
		pSixes = (sixes * 1.0) / ballsPlayed;
		ones = (totalRuns - (fours * 4) - (sixes * 6));
		pOnes = (ones * 1.0) / ballsPlayed;
		pZero = ((ballsPlayed - fours - sixes- ones)*1.0)/ballsPlayed;
		if (balls != 0)
		{
			pWicket = wickets * 1.0 / balls;
		}
	}

	bool canBall() {
		if (strcmp(role, "Bat") == 0) {
			return false;
		}
		return true;
	}

	~Player();
};