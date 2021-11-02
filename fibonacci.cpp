#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

typedef long long int llt;
typedef vector<vector<llt> > mat;
llt arr[4], m;

mat operator*(const mat& a, const mat& b) {
	llt R = a.size();
	mat result(R, vector<llt>(R));
	for (llt i = 0; i < R; ++i)
		for (llt j = 0; j < R; ++j)
			for (llt k = 0; k < R; ++k)
				result[i][j] += (a[i][k] * b[k][j]) % m;
	return result;
}

mat fib(mat a, llt n) {
	llt R = a.size();
	mat result(R, vector<llt>(R));
	for (llt i = 0; i < R; ++i) {
		result[i][i] = 1;
	}
	while (n > 0) {
		if (n % 2 == 1) {
			result = result * a;
		}
		n /= 2;
		a = a * a;
	}
	return result;
}

llt ans(llt* arr) {
	llt L = (arr[0] * arr[1]) % m;
	llt R = (arr[2] * arr[3]) % m;
	return (L + R) % m;
}

int main() {
	ofstream out("fibonacci.out");
	ifstream inp("fibonacci.inp");
	int t;
	inp >> t;
	while (t--) {
		for (int i = 0; i < 4; i++) inp >> arr[i];
		inp >> m;
		mat a = { {1, 1}, {1, 0} };
		llt results[4] = { 0, };
		for (int i = 0; i < 4; ++i) {
			mat result = fib(a, arr[i] - 1);
			results[i] = (result[1][0] + result[1][1]) % m;
		}
		out << ans(results) << endl;
	}
	inp.close(), out.close();
	return 0;
}