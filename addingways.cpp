#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main() {
	ifstream inp("addingways.inp");
	ofstream out("addingways.out");

	int n, k;
	while (true) {
		inp >> n >> k;
		if (n == 0 && k == 0) break;

		int MOD = 1000000007;
		long long int res=0, dp[301][301] = { 0, };

		for (int i = 1; i <= n; i++) {
			dp[i][1] = 1;
			dp[i][i] = 1;
		}
		for (int i = 3; i <= n - k; i++) {
			for (int j = 2; j <= k; j++) {
				if (i <= j)continue;
				for (int u = 1; u <= j; u++) {
					dp[i][j] += (dp[i - j][u] % MOD);
				}
			}
		}
		if (n > k) {
			for (int i = 1; i <= k; i++) {
				res += (dp[n - k][i]) % MOD;
			}

			out << res % MOD << endl;
		}
		else if(n<k) out << 0 << endl;
		else out << 1 << endl;
		
	}

	inp.close(), out.close();
}