#include<stdio.h>

int main() {
	FILE * inp = fopen("soccer.inp", "r");
	FILE * out = fopen("soccer.out", "w");
	int T, n, k, x, y, a, b, i, j, l, m;

	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		int grade[41] = { 0, }; //등수 정보.
		int vs[41] = { 0, };
		int goalP[41] = { 0, }; //goal넣은 수
		int goalM[41] = { 0, }; //goal먹힌 수
		int goalA[41] = { 0, }; //away경기에서 넣은 골수
		fscanf(inp, "%d %d", &n, &k);
		for (j = 1; j <= k; j++) {
			for (l = 1; l <= 2 * (n - 1); l++) {
				for (m = 1; m <= n / 2; m++) {
					fscanf(inp, "%d-%d %d %d", &x, &y, &a, &b);
					goalP[x] += a; goalM[x] -= b;
					goalP[y] += b; goalM[y] -= a;
					if (a > b) vs[x] += 3;
					else if (a < b) vs[y] += 3;
					else vs[x] += 1, vs[y] += 1;
					goalA[x] += a;
				}
			}
		}

		int max_i = 1;
		int max = vs[1];
		for (l = 1; l <= n; l++) {
			int a_max[41] = { 0, };
			int max_i2 = 0;//같은게 두개가 아닐수도있지..
			int cnt = 0;
			for (j = 1; j <= n; j++) {
				if (max < vs[j]) {
					max = vs[j]; max_i = j;
					for (m = 1; m <= 40; m++) {
						a_max[m] = 0;
					}
				}
				else if (max == vs[j]) {
					if ((goalP[j] + goalM[j]) > (goalP[max_i] + goalM[max_i])) {
						max = vs[j]; max_i = j;
						for (m = 1; m <= 40; m++) {
							a_max[m] = 0;
						}
					}
					else if ((goalP[j] + goalM[j]) == (goalP[max_i] + goalM[max_i])) {
						if (goalA[j] > goalA[max_i]) {
							max = vs[j]; max_i = j;
						}
						else if (goalA[j] == goalA[max_i]) {
							if (j != 1&&max!=-1) {
								max_i2 = j;
								a_max[j] = j;
							}
						}
					}
				}
				if (j == n) {
					grade[max_i] = l; vs[max_i] = -1; max = -1;
					if ((max_i2 != 0&&max_i2!=-1)) {
						for (m = 1; m <= 40; m++) {
							if (a_max[m] != 0) vs[m] = -1, grade[m] = l, cnt++;
						}
						l += cnt;
					}
				}
			}
		}
		fprintf(out, "Test Case #%d:", i + 1);
		for (j = 1; j <= n; j++) fprintf(out, " %d", grade[j]);
		fprintf(out, "\n");
	}
	fclose(inp); fclose(out);
}