#include <iostream>
#include <string>
#include<fstream>
#include <unordered_set>

using namespace std;

unordered_set<string> sameThings;

__inline void myPush(string& str) {
	auto finding = sameThings.find(str);
	if (finding == sameThings.end()) { // set에 존재하지 않는 경우, 중복방지
		sameThings.insert(str);
	}
}

__inline bool isExist(string& target) {
	auto finding = sameThings.find(target);
	return finding != sameThings.end() ? true : false;
}

int main() {

	ofstream out("cube.out");
	ifstream inp("cube.inp");

	string input;
	while (getline(inp, input)) {
		string origin = input.substr(0, 6), target = input.substr(6);

		if (origin == target) {
			out << "TRUE"<<endl;
			continue;
		}

		const int CASES = 23;
		const int shuffle[CASES][6] = {
		   {0, 3, 1, 4, 2, 5},
		   {0, 4, 3, 2, 1, 5},
		   {0, 2, 4, 1, 3, 5},

		   {1, 5, 2, 3, 0, 4},
		   {1, 3, 5, 0, 2, 4},
		   {1, 0, 3, 2, 5, 4},
		   {1, 2, 0, 5, 3 ,4},

		   {5, 4, 2, 3, 1, 0},
		   {5, 3, 4, 1, 2, 0},
		   {5, 1, 3, 2, 4, 0},
		   {5, 2, 1, 4, 3, 0},

		   {4, 0, 2, 3, 5, 1},
		   {4, 3, 0, 5, 2, 1},
		   {4, 5, 3, 2, 0, 1},
		   {4, 2, 5, 0, 3, 1},

		   {2, 1, 5, 0, 4, 3},
		   {2, 0, 1, 4, 5, 3},
		   {2, 4, 0, 5, 1, 3},
		   {2, 5, 4, 1, 0, 3},

		   {3, 1, 0, 5, 4, 2},
		   {3, 5, 1, 4, 0, 2},
		   {3, 4, 5, 0, 1, 2},
		   {3, 0, 4, 1, 5, 2}
		};

		for (int i = 0; i < CASES; ++i) {
			string curr = "";
			for (const int& idx : shuffle[i]) {
				curr += origin[idx];
			}
			myPush(curr);
		}

		isExist(target) ? out << "TRUE"<<endl : out << "FALSE"<<endl;
		sameThings.clear();
	}


	out.close(), inp.close();
	return 0;
}