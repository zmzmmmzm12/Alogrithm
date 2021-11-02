#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream inp("coin.inp");
	ofstream out("coin.out");
	int t, a, b, c, check, arr[101][101][101];
	arr[0][0][0] = 1;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				int check2 = 0;
				for (int i2 = i - 1; (i2 >= 0 && i2 >= i - 3); i2--) {
					if (arr[i2][j][k] == 0) {
						arr[i][j][k] = 1;
						check2 = 1;
						break;
					}
				}
				if (check2 == 0) {
					for (int j2 = j - 1; (j2 >= 0 && j2 >= j - 3); j2--) {
						if (arr[i][j2][k] == 0) {
							arr[i][j][k] = 1;
							check2 = 1;
							break;
						}
					}
					if (check2 == 0) {
						for (int k2 = k - 1; (k2 >= 0 && k2 >= k - 3); k2--) {
							if (arr[i][j][k2] == 0) {
								arr[i][j][k] = 1;
								check2 = 1;
								break;
							}
						}
					}
				}
			}
		}
	}
	inp >> t;
	for (int i = 0; i < t; i++) {
		inp >> a >> b >> c;
		if (arr[a][b][c]==1) check = 1;
		else check = -1;
		out << "(" << a << " " << b << " " << c << ") : " << check << "\n";
	}
	inp.close();
	out.close();
}