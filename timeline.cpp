#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE * inp = fopen("timeline.inp", "r");
	FILE * oup = fopen("timeline.out", "w");
	int T, i, j, N, cnt, ya, yb, ma, mb, da, db, start,finish;
	fscanf(inp, "%d", &T);

	for (i = 0; i < T; i++) {
		int max = 0;
		int arr[20161212] = { 0, };
		cnt = 0;
		fscanf(inp, "%d", &N);
		for (j = 0; j < N; j++) {
			fscanf(inp, "%d.%d.%d %d.%d.%d", &ya, &ma, &da, &yb, &mb, &db);
			start = ya * 10000 + ma * 100 + da;
			finish = yb * 10000 + mb * 100 + db;
			arr[start] += 1;
			arr[finish] -= 1;
		}
		for (j = 10101; j <= 20161212; j++) {
			cnt += arr[j];
			if (cnt > max) max = cnt;
		}
		if (i != T - 1) fprintf(oup, "%d\n", max);
		else fprintf(oup, "%d", max);
	}
	fclose(inp);
	fclose(oup);
}