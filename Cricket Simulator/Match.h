#pragma once
#include "Team.h"
#include <string>
using namespace std;

class Match
{
public:
	Team* team1;
	Team* team2;
	int balls = 0;

	Match(Team *t1, Team *t2) {
		team1 = t1;
		team2 = t2;
	}

	void play()
	{
		Player bowler;

		Player batsman1 = team2->getBatsman();
		//cout << batsman1.name << " is batting" << "\n";

		Player batsman2 = team2->getBatsman();
		//cout << batsman2.name << " is batting2" << "\n";

		Player* curBatsman = &batsman2;

		for (int balls = 0; balls < 120 && team2->batsmanInd != team2->batting.size(); balls++)
		{
			if (balls % 6 == 0)
			{
				if (curBatsman == &batsman1)
				{
					curBatsman = &batsman2;
					//cout << batsman2.name << " is batting" << "\n";

				}
				else
				{
					curBatsman = &batsman1;
					//cout << batsman1.name << " is batting" << "\n";

				}

				bowler = team1->getBowler();
				//cout << bowler.name << " is bowling" << "\n";

			}
			int runs = 0;
			team2->ballsFaced++;

			if (bowler.takesWicket())
			{
				bowler.ballsBowled++;
				bowler.wicketsTaken++;
				//cout << bowler.name << " outs " << curBatsman->name << "\n";

				curBatsman->ballsBatted++;
				*curBatsman = team2->getBatsman();
				team2->wicketsLost++;
			}
			else
			{
				//batsman
				runs = curBatsman->bats(balls);
				curBatsman->ballsBatted++;
				if (runs==4)
				curBatsman->foursScored++;
				if (runs==6)
				curBatsman->sixesScored++;
				curBatsman->runsScored += runs;

				//team
				team2->runsScored += runs;
				team2->runsScoredIn1Match += runs;
				
				//bowler
				bowler.ballsBowled++;
				bowler.runsGiven += runs;
				//cout << curBatsman->name << " scores " << runs<<"\n";
				if (runs == 1)
				{
					if (curBatsman == &batsman1)
					{
						curBatsman = &batsman2;
					}
					else
					{
						curBatsman = &batsman1;
					}
				}
			}
		}

	}
}; 