#pragma once
#include "Team.h"
#include <string>
using namespace std;

class Match
{
public:
	Team team1;
	Team team2;
	int balls = 0;
	
	Match(string t1, string t2) {
		team1 = Team(t1);
		team2 = Team(t2);
	}

	void play()
	{
		Player bowler;

		Player batsman1 = team2.batting.front();
		team2.batting.pop();

		Player batsman2 = team2.batting.front();
		team2.batting.pop();

		Player* curBatsman = &batsman1;

		for (int balls = 0; balls < 120 && !team2.batting.empty() ; balls++)
		{
			if (balls % 6 == 0)
			{
				if (curBatsman == &batsman1)
				{
					curBatsman = &batsman2;
				}
				else
				{
					curBatsman = &batsman1;
				}
				
				bowler = team1.bowling.front();
				team1.bowling.pop();
				team1.bowling.push(bowler);
			}
			int runs = 0;
			if (bowler.takesWicket())
			{
				bowler.wicketsTaken++;
				if (curBatsman == &batsman1) batsman1.isOut = true;
				else batsman2.isOut = true;

				*curBatsman = team2.batting.front();
				team2.batting.pop();
				team2.wicketsLost++;
			}
			else
			{
				runs = curBatsman->bats();
				curBatsman->runsScored += runs;
				team2.runsScored += runs;
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

