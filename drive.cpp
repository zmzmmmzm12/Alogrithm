#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

int arrg[101][101];
int arrg2[101][101];
int dp[105][105][300][2];

int main() {
	ifstream inp("drive.inp");
	ofstream out("drive.out");
	int t, n, m, l, g;
	inp >> t;
	while (t--) {
		inp >> n >> m >> l >> g;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m - 1; j++)
				inp >> arrg[i][j];
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < m; j++)
				inp >> arrg2[i][j];
		memset(dp, 63, sizeof(dp));
		dp[0][0][0][0] = 0, dp[0][0][0][1] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 250; k++) {
					if (i + 1 < n) {
						dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][0] + arrg2[i][j]);
						dp[i + 1][j][k + 1][0] = min(dp[i + 1][j][k + 1][0], dp[i][j][k][1] + arrg2[i][j]);
					}
					if (j + 1 < m) {
						dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], dp[i][j][k][1] + arrg[i][j]);
						dp[i][j + 1][k + 1][1] = min(dp[i][j + 1][k + 1][1], dp[i][j][k][0] + arrg[i][j]);
					}
				}
			}
		int tmp = 1111111111;
		for (int i = 0; i < 250; i++) {
			if (dp[n - 1][m - 1][i][0] <= g)
				tmp = min(tmp, i);
			if (dp[n - 1][m - 1][i][1] <= g)
				tmp = min(tmp, i);
		}
		int re = 0;
		if (tmp == 1111111111) {
			re = -1;
		}
		else {
			re = (n - 1)*l + (m - 1)*l + tmp;
		}
		out << re << endl;
	}
	inp.close(), out.close();
}