#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main() {
	ifstream inp("stickers.inp");
	ofstream out("stickers.out");
	int T, n, i, j;
	char temp;
	int dp[2][100002] = { 0, };
	inp >> T;
	while(T--){
		inp >> n;
		for (i = 0; i < 2; i++)
			for (j = 2; j < n + 2; j++)
				inp >> dp[i][j];
		for (j = 2; j < n + 2; j++) {
			for (i = 0; i < 2; i++) {
				if (i == 1) dp[i][j] +=max(dp[i - 1][j - 1], dp[i - 1][j - 2]);
				else dp[i][j] += max(dp[i + 1][j - 1], dp[i + 1][j - 2]);
			}
		}
		out << max(dp[0][n + 1], dp[1][n + 1]) << endl;
	}
	inp.close(), out.close();
}