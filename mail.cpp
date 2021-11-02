#include<stdio.h>

int main() {
	int A[] = { 0,0,0,0,0,0 };
	int B[] = { 0,0,1,1,1,1 };
	int C[] = { 0,1,0,0,1,1 };
	int D[] = { 0,1,1,1,0,0 };
	int E[] = { 1,0,0,1,1,0 };
	int F[] = { 1,0,1,0,0,1 };
	int G[] = { 1,1,0,1,0,1 };
	int H[] = { 1,1,1,0,1,0 };
	int arr[6];
	int i, j, k, N, T;
	char c;
	FILE * inp = fopen("mail.inp", "r");
	FILE * out = fopen("mail.out", "w");
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(inp, "%d", &N);
		fscanf(inp, "%c", &c);
		j = 0;
		while (j < N) {
			int cntA = 0, cntB = 0, cntC = 0, cntD = 0, cntE = 0, cntF = 0, cntG = 0, cntH = 0;
			for (k = 0; k < 6; k++) {
				fscanf(inp, "%c", &c);
				arr[k] = c - '0';
				if (arr[k] == A[k]) cntA++;
				if (arr[k] == B[k]) cntB++;
				if (arr[k] == C[k]) cntC++;
				if (arr[k] == D[k]) cntD++;
				if (arr[k] == E[k]) cntE++;
				if (arr[k] == F[k]) cntF++;
				if (arr[k] == G[k]) cntG++;
				if (arr[k] == H[k]) cntH++;
			}
			if (cntA == 6 || cntA == 5) fprintf(out, "A");
			else if (cntB == 6 || cntB == 5) fprintf(out, "B");
			else if (cntC == 6 || cntC == 5) fprintf(out, "C");
			else if (cntD == 6 || cntD == 5) fprintf(out, "D");
			else if (cntE == 6 || cntE == 5) fprintf(out, "E");
			else if (cntF == 6 || cntF == 5) fprintf(out, "F");
			else if (cntG == 6 || cntG == 5) fprintf(out, "G");
			else if (cntH == 6 || cntH == 5) fprintf(out, "H");
			else fprintf(out, "X");
			j++;
		}
		fscanf(inp, "%c", &c);
		fprintf(out, "\n");
	}
	fclose(inp); fclose(out);
}
