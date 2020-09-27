#include <string>
#include <iostream>
#include "Team.h"
#include "Match.h"
using namespace std;
int main() {
	string team1;
	string team2;
	cin >> team1;
	cin >> team2;
	Team t1(team1);
	Team t2(team2);
	int n = 1;

	for (int i = 0; i < n; i++) {
		Match match1(&t1, &t2);
		Match match2(&t2, &t1);
		match1.play();
		t2.reset();
		match2.play();
		t1.reset();
	}
	cout << t1.runsScored << "\n";
	cout << t2.runsScored << "\n";

	return 0;
}