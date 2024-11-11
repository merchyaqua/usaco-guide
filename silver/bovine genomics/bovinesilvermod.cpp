#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const std::map<char, int> GENOME_ID{{'A', 0}, {'T', 1}, {'C', 2}, {'G', 3}};

int main() {
	std::ifstream read("cownomics.in");

	int cow_num;
	int genome_len;
	read >> cow_num >> genome_len;

	vector<vector<int>> spotted(cow_num, vector<int>(genome_len));
	for (int s = 0; s < cow_num; s++) {
		std::string genome;
		read >> genome;
		for (int g = 0; g < genome_len; g++) {
			// A -> 0, C -> 1, T -> 2, G -> 3
			spotted[s][g] = GENOME_ID.at(genome[g]);
		}
	}

	vector<vector<int>> plain(cow_num, vector<int>(genome_len));
	for (int p = 0; p < cow_num; p++) {
		std::string genome;
		read >> genome;
		for (int g = 0; g < genome_len; g++) {
			plain[p][g] = GENOME_ID.at(genome[g]);
		}
	}

	int valid_sets = 0;
	// Loop through every possible group of 3.
	for (int a = 0; a < genome_len; a++) {
		for (int b = a + 1; b < genome_len; b++) {
			for (int c = b + 1; c < genome_len; c++) {
				vector<bool> spotted_ids(64);
				for (int sc = 0; sc < cow_num; sc++) {
					/*
					 * By multiplying the first, second, and
					 * third digits by 16, 4, and 1 respectively, we can
					 * get a number unique to that combination.
					 */
					int total = (spotted[sc][a] * 16 + spotted[sc][b] * 4 +
					             spotted[sc][c] * 1);
					spotted_ids[total] = true;
				}

				bool valid = true;
				for (int pc = 0; pc < cow_num; pc++) {
					int total = (plain[pc][a] * 16 + plain[pc][b] * 4 +
					             plain[pc][c] * 1);
					// We can't tell the spotted & plain cows apart.
					if (spotted_ids[total]) {
						valid = false;
						break;
					}
				}

				valid_sets += valid;
			}
		}
	}

	std::ofstream("cownomics.out") << valid_sets << endl;
}