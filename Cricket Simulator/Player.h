# include <string>
# include <math.h>
///using namespace std;

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
		if (role != "Bat") {
			return false;
		}
		return true;
	}

	~Player();
};