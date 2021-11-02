#include<stdio.h>

enum Bool{t,f};

int main() {
	FILE * inp = fopen("paper.inp", "r");
	FILE * out = fopen("paper.out", "w");
	int T, N, M, i, j, k, cnt;
	int arrN[50][49];
	int arrM[49][50];
	enum Bool b;
	//이차원으로 굳이 짤 필요없을거같긴함
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		b = t;
		fscanf(inp, "%d %d", &N, &M);
		for (j = 0; j < N; j++) {
			for (k = 0; k < M - 1; k++) {
				fscanf(inp, "%d", &arrN[j][k]);
			}
		}
		for (j = 0; j < N - 1; j++) {
			for (k = 0; k < M; k++) {
				fscanf(inp, "%d", &arrM[j][k]);
			}
		}
		for (j = 0; j < N - 1; j++) {
			for (k = 0; k < M-1; k++) {
				cnt = 0;
				if (arrN[j][k] == 1) cnt++;
				if (arrN[j + 1][k] == 1) cnt++;
				if (arrM[j][k] == 1)cnt++;
				if (arrM[j][k + 1] == 1)cnt++;
				if (cnt==0||cnt == 2 || cnt==4) { b = f; break; }
			}
			if (b == f) break;
		}
		if (b == t) fprintf(out, "1 ");
		else fprintf(out, "0 ");
	}
	fclose(inp); fclose(out);
}