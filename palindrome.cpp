#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	ofstream out("palindrome.out");
	ifstream inp("palindrome.inp");

	int t;
	inp >> t;

	while (t > 0) {
		string s;
		inp >> s;
		int n = s.length();
		int **arr = new int*[n]; //[n][n]동적할당
		for (int i = 0; i < n; i++) {
			arr[i] = new int[n];
			memset(arr[i], 0, sizeof(int)*n); //초기화
		}
		arr[0][0] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n - i; j++) {
				if (s.at(j) == s.at(i + j)) {
					arr[j][i + j] = arr[j + 1][i + j - 1];
				}
				else {
					arr[j][i + j] = 1 + min(arr[j][i + j - 1], arr[j + 1][i + j]);
				}

			}
		}
		int mod = arr[0][n - 1];
		if (mod == 0) out << "0"<<endl;
		else if (mod == 1) out << "1" << endl;
		else if (mod == 2) out << "2" << endl;
		else out << "-1" << endl;
		t--;
	}

	out.close(), inp.close();
}