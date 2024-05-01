// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void setIO(){
	freopen("hps.in","r",stdin);
	freopen("hps.out", "w", stdout);
}

// https://usaco.org/index.php?page=viewproblem2&cpid=691
int main() {
	/* how to improve:
	- just use an array instead of map for such a small set it won't make a difference and they're unique chars
	- computing prefix sums - start at 0, calculate the one for 1. easy, no 1-indexing or repetition
	- can use prefix and suffix arrays since we only need two sections. so for every switching bound a, we add the prefix and suffix of that.*/
	setIO();
	int n;
	cin >> n;
	map<char, vector<int>> wins;
	string options = "HPS";
	vector<int> empty(n);
	// initialise map with empty vectors
	for (int i = 0; i < 3; i++){
		wins[options[i]] = empty;
	}
	for (int i = 0; i < n; i++){
		char game;
		cin >> game;
		// for each round, determine which move wins
		switch (game){
			case 'H':
				wins['P'][i] = 1;
				break;
			case 'P':
				wins['S'][i] = 1;
				break;
			case 'S':
				wins['H'][i] = 1;
				break;

		}
	}		
	// cout << wins['P'][0] << ' ' << wins['S'][0] << ' ' << wins['H'][0] << endl;
	// compute prefix sums
	for (int i = 1; i < n; i++){
		// cout << wins['P'][i] << ' ' << wins['S'][i] << ' ' << wins['H'][i] << endl;
		wins['P'][i] += wins['P'][i-1];
		wins['S'][i] += wins['S'][i-1];
		wins['H'][i] += wins['H'][i-1];
	}

	int ans = 0;
	// loop over all possible before/after switch combinations of moves
	for (int i = 0; i < 3; i++){
		int temp = 0;
		for (int j = 0; j < 3; j++){
			if (i == j) ans = max(ans, wins[options[i]][n-1]);
			else {
				// for each possible switch time, calculate how many actual wins this gives us
				for (int t = 0; t < n; t++) {
					// prefix of first + section of 2nd 
					temp = wins[options[i]][t] + wins[options[j]][n-1]- wins[options[j]][t];
					ans = max(ans, temp);
					// cout << t << ": "<< ans << endl;
				}
			}
		}
	}
	cout << ans;

}
