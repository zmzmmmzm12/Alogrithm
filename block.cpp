#include<stdio.h>
#include<stdlib.h>

void make(int **arr, int N);

FILE * inp = fopen("block.inp", "r");
FILE * out = fopen("block.out", "w");

int main() {
	int T, N, i, j, k, l;
	fscanf(inp, "%d", &T);
	
	for (i = 0; i < T; i++) {
		fscanf(inp, "%d", &N);
		
		int **arr = (int **)malloc(sizeof(int*)*N);
		for (j = 0; j < N; j++) arr[j] = (int *)malloc(sizeof(int)*j);
		
		for (j = 0; j < N; j++) {
			for (k = 0; k <= j; k++) {
				fscanf(inp, "%d", &arr[j][k]);
			}
		}

		make(arr,N);
		
	}
	fclose(inp); fclose(out);
}

void make(int **arr, int N) {
	int i, j, k;
	for (k = 0; k < N; k++) {
		for (i = 0; i < N - 1; i++) {
			for (j = 0; j <= i; j++) {
				if (arr[i][j] == -1) {
					if (arr[i + 1][j] != -1 && arr[i + 1][j + 1] != -1)
						arr[i][j] = (arr[i + 1][j] + arr[i + 1][j + 1])%100;
				}
				else {
					if (arr[i + 1][j] == -1 && arr[i + 1][j + 1] != -1)
						arr[i + 1][j] = (arr[i][j] - arr[i + 1][j + 1]+100)%100;
					else if (arr[i + 1][j] != -1 && arr[i + 1][j + 1] == -1)
						arr[i + 1][j + 1] = (arr[i][j] - arr[i + 1][j]+100)%100;
				}
			}
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j <= i; j++) {
			fprintf(out, "%d ", arr[i][j]);
		}
		fprintf(out, "\n");
	}
}