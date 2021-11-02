#include<stdio.h>
#include<stdlib.h>

struct question {
	int num, s, b;
};

int cmp(const void *a, const void *b) {
	int n1 = *(int *)a;
	int n2 = *(int *)b;
	if (n1 < n2) return -1;
	else if (n1 > n2) return 1;
	else return 0;
}

int main() {
	FILE * inp = fopen("numgame.inp", "r");
	FILE * out = fopen("numgame.out", "w");
	int T, k, i, j,l,m, cnt;
	int a[4], b[4];
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		int re[10000];
		cnt = 0;
		fscanf(inp, "%d", &k);
		struct question *Q=(struct question *)malloc(sizeof(struct question)*k);
		for (j = 0; j < k; j++) {
			fscanf(inp, "%d %d %d", &Q[j].num, &Q[j].s, &Q[j].b);
		} //k개만큼 다받고
		for (j = 1234; j <= 9876; j++) {
			int count = 0;
			a[0] = j / 1000, a[1] = j / 100 % 10, a[2] = j / 10 % 10, a[3] = j % 10;
			if (a[0] == a[1] || a[0] == a[2] || a[0] == a[3] || a[1] == a[2] || a[1] == a[3] || a[2] == a[3]) continue;
			else if (a[0] == 0 || a[1] == 0 || a[2] == 0 || a[3] == 0) continue;
			for (l = 0; l < k; l++) { //비교
				int strike = 0, baseball = 0 ;
				b[0] = Q[l].num / 1000, b[1] = Q[l].num / 100 % 10, b[2] = Q[l].num / 10 % 10, b[3] = Q[l].num % 10;
				for (m = 0; m < 4; m++) {
					if (a[m] == b[m]) strike++;
					if (a[m] == b[(m + 1) % 4] || a[m] == b[(m + 2) % 4] || a[m] == b[(m + 3) % 4]) baseball++;
				}
				if (strike == Q[l].s&&baseball == Q[l].b) count++;
			}
			if (count == k) { 
				re[cnt] = j;
				cnt++; 
			}
		}
		//정렬은 qsort함수쓰자.
		qsort(re, cnt, sizeof(int), cmp);
		if (cnt > 6) {
			fprintf(out, "%d\n", cnt);
			fprintf(out, "%d\n", re[0]);
			fprintf(out, "%d\n", re[1]);
			fprintf(out, "%d\n", re[2]);
			fprintf(out, "%d\n", re[cnt-3]);
			fprintf(out, "%d\n", re[cnt-2]);
			fprintf(out, "%d\n", re[cnt-1]);
		}
		else {
			fprintf(out, "%d\n", cnt);
			for (j = 0; j < cnt; j++) {
				fprintf(out, "%d\n", re[j]);
			}
		}

	}

	fclose(inp), fclose(out);
}