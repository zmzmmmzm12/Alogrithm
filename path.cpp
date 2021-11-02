#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;

int c, m, n, k, path[110][110], mpay[110][110], npay[110][110], cost[110][110][210], kcount[110][110][210];
int bm[1000], bn[1000], cc;


void pa() {


	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {

			if (a - 1 >= 0) {

				if (a - 1 == 0 && b == 0) {
					kcount[a][b][1] = 1;
					cost[a][b][1] = npay[a - 1][b];
				}
				else if (path[a - 1][b] == 1) {
					for (int d = 1; d <= kcount[a - 1][b][0] + 1; d++) {
						kcount[a][b][0] = d - 1;
						kcount[a][b][d + 1] += kcount[a - 1][b][d];
						if (kcount[a][b][d + 1] >= 100000)kcount[a][b][d + 1] %= 100000;
						if (cost[a - 1][b][d] != 0)cost[a][b][d + 1] = cost[a - 1][b][d] + npay[a - 1][b];
					}
					kcount[a][b][0]++;
				}
				else {
					for (int d = 1; d <= kcount[a - 1][b][0] + 1; d++) {
						kcount[a][b][0] = d - 1;
						kcount[a][b][d] += kcount[a - 1][b][d];
						if (kcount[a][b][d] >= 100000)kcount[a][b][d] %= 100000;
						if (cost[a - 1][b][d] != 0)cost[a][b][d] = cost[a - 1][b][d] + npay[a - 1][b];
					}

				}
			}
			if (b - 1 >= 0) {
				if (a == 0 && b - 1 == 0) {
					kcount[a][b][1] = 1;
					cost[a][b][1] = mpay[a][b - 1];
				}
				else if (path[a][b - 1] == 1) {
					for (int d = 1; d <= kcount[a][b - 1][0] + 1; d++) {
						kcount[a][b][0] = max(kcount[a][b][0], d - 1);
						kcount[a][b][d + 1] += kcount[a][b - 1][d];
						if (kcount[a][b][d + 1] >= 100000)kcount[a][b][d + 1] %= 100000;
						if (cost[a][b - 1][d] != 0 && cost[a][b][d + 1] == 0)cost[a][b][d + 1] = cost[a][b - 1][d] + mpay[a][b - 1];
						else if (cost[a][b - 1][d] != 0 && cost[a][b][d + 1] != 0)cost[a][b][d + 1] = min(cost[a][b][d + 1], cost[a][b - 1][d] + mpay[a][b - 1]);
					}
					kcount[a][b][0]++;
				}
				else {
					for (int d = 1; d <= kcount[a][b - 1][0] + 1; d++) {
						kcount[a][b][0] = max(kcount[a][b][0], d - 1);
						kcount[a][b][d] += kcount[a][b - 1][d];
						if (kcount[a][b][d] >= 100000)kcount[a][b][d] %= 100000;
						if (cost[a][b - 1][d] != 0 && cost[a][b][d] == 0)cost[a][b][d] = cost[a][b - 1][d] + mpay[a][b - 1];
						else if (cost[a][b - 1][d] != 0 && cost[a][b][d] != 0)cost[a][b][d] = min(cost[a][b][d], cost[a][b - 1][d] + mpay[a][b - 1]);
					}

				}
			}


		}
	}

	return;

}

void bp(int i) {

	cc = 0;
	bm[cc] = m - 1;
	bn[cc] = n - 1;
	cc++;
	int sum = cost[m - 1][n - 1][i];
	while (1) {

		if (bm[cc - 1] == 0 && bn[cc - 1] == 0)break;

		if ((path[bm[cc - 1]][bn[cc - 1] - 1] == 1) && (cost[bm[cc - 1]][bn[cc - 1] - 1][i - 1] + mpay[bm[cc - 1]][bn[cc - 1] - 1] == sum)) {
			bm[cc] = bm[cc - 1];
			bn[cc] = bn[cc - 1] - 1;
			sum -= mpay[bm[cc - 1]][bn[cc - 1] - 1];
			cc++;
			i--;
		}
		else if ((path[bm[cc - 1]][bn[cc - 1] - 1] == 0) && (cost[bm[cc - 1]][bn[cc - 1] - 1][i] + mpay[bm[cc - 1]][bn[cc - 1] - 1] == sum)) {
			bm[cc] = bm[cc - 1];
			bn[cc] = bn[cc - 1] - 1;
			sum -= mpay[bm[cc - 1]][bn[cc - 1] - 1];
			cc++;
		}

		else if ((path[bm[cc - 1] - 1][bn[cc - 1]] == 1) && (cost[bm[cc - 1] - 1][bn[cc - 1]][i - 1] + npay[bm[cc - 1] - 1][bn[cc - 1]] == sum)) {

			bm[cc] = bm[cc - 1] - 1;
			bn[cc] = bn[cc - 1];
			sum -= npay[bm[cc - 1] - 1][bn[cc - 1]];
			cc++;
			i--;

		}
		else if ((path[bm[cc - 1] - 1][bn[cc - 1]] == 0) && (cost[bm[cc - 1] - 1][bn[cc - 1]][i] + npay[bm[cc - 1] - 1][bn[cc - 1]] == sum)) {

			bm[cc] = bm[cc - 1] - 1;
			bn[cc] = bn[cc - 1];
			sum -= npay[bm[cc - 1] - 1][bn[cc - 1]];
			cc++;

		}


	}
	return;

}


int main() {

	ifstream fin;
	ofstream fout;

	fin.open("path.inp");
	fout.open("path.out");
	int c1 = 1;
	fin >> c;
	while (c--) {
		memset(path, 0, sizeof(path));
		memset(kcount, 0, sizeof(kcount));
		memset(cost, 0, sizeof(cost));
		fin >> m >> n >> k;
		int a, b;

		for (int i = 0; i < k; i++) {
			fin >> a >> b;
			path[a][b] = 1;
		}
		for (int i = 0; i < m; i++)for (int j = 0; j < n - 1; j++)fin >> mpay[i][j];
		for (int i = 0; i < m - 1; i++)for (int j = 0; j < n; j++)fin >> npay[i][j];
		pa();

		fout << "Test Case No:" << c1++ << endl;
		for (int i = 1; i <= kcount[m - 1][n - 1][0] + 1; i++) {
			if (kcount[m - 1][n - 1][i] != 0) {
				fout << "k:" << i - 1 << " count:" << kcount[m - 1][n - 1][i] << " cost:" << cost[m - 1][n - 1][i] << endl;
				bp(i);
				fout << "(0,0)";
				for (int j = 1; j < cc; j++)fout << "->(" << bm[cc - 1 - j] << ',' << bn[cc - 1 - j] << ")";
				fout << endl;
			}
		}
		if (c != 0)fout << endl;
	}

	fin.close();
	fout.close();

}