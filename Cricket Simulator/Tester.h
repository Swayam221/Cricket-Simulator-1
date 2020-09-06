#pragma once
#include "Player.h"
#include <iostream>
using namespace std;

class Tester
{
	int main() {
		Player player("Rohit Sharma", "Bat", 4898, 130.82, 431, 194, 0, 0);
		cout << player.name << "\t" ;
		cout << player.role << "\t" ;
		cout << player.pFours << "\t";
		cout << player.pOnes << "\t" ;
		cout << player.pSixes << "\t" ;
		cout << player.pZero << "\t" ;
		cout << player.pWicket << "\t" ;
		cout << player.canBall() << "\t" ;
		return 0;
	}
};

