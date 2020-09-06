#pragma once
#include "Team.h"
#include <string>
using namespace std;

class Match
{
public:
	Team team1;
	Team team2;
	
	Match(string t1, string t2) {
		team1 = Team(t1);
		team2 = Team(t2);
	}
};

