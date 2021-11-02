#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int n, W;
int s[202];
long long dp[202][80002];

int main() {
	ifstream inp("sum.inp");
	ofstream out("sum.out");

	int t;
	inp >> t;

	while (t--) {
		inp >> n >> W;
		for (int i = 0; i < n; i++) {
			inp >> s[i];
		}
		fill(&dp[0][0], &dp[201][80002], (long long)0); //50Á¡
		sort(s,s+n);
		for (int i = 0; i < n; i++) {
			dp[i+1][s[i]] = 1;
		}
		long long check = 0;
		for (int i = 1; i <= n; i++) {
			check += s[i - 1];
			for (int j = 1; j <= W; j++) {
				if (j < s[i-1]) {
					dp[i][j] = dp[i - 1][j] % 100000;
				}
				else {
					dp[i][j] += (dp[i - 1][j] % 100000 + dp[i - 1][j - s[i-1]] % 100000);
				}
				if (check<=j) break;
			}
		}

		long long res = dp[n][W] % 100000;
		out << res << endl;
	}
}