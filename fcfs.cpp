#include<stdio.h>

void bubbleSort(int a[], int b[], int c[], int N) {
	for (int i = 0; i < N; i++) {
		int j;
		for (j = 0; j < N - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int min = a[j + 1];
				a[j + 1] = a[j];
				a[j] = min;
				min = b[j + 1];
				b[j + 1] = b[j];
				b[j] = min;
				min = c[j + 1];
				c[j + 1] = c[j];
				c[j] = min;
			}
			if (a[j] == a[j + 1]) { //도착시간동일
				if (c[j] > c[j + 1]) { //프로세스 번호 작은거부터 실행
					int min = a[j + 1];
					a[j + 1] = a[j];
					a[j] = min;
					min = b[j + 1];
					b[j + 1] = b[j];
					b[j] = min;
					min = c[j + 1];
					c[j + 1] = c[j];
					c[j] = min;
				}
			}
		}
	}
}

int main() {
	FILE * inp = fopen("fcfs.inp", "r");
	FILE * out = fopen("fcfs.out", "w");
	int n, wating=0, run=0, tmp1, tmp2, i, j, k = 0;
	int number[50], arrive[50], use[50];
	fscanf(inp, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d %d %d", &number[i], &arrive[i], &use[i]);
	}
	bubbleSort(arrive, use, number, n);
	
	for (i = 1; i < n; i++) {
		tmp1 = 0;
		for (j = k; j < i; j++) {
			tmp1 += use[j];
		}
		tmp2 = tmp1 - arrive[i] + arrive[k];
		if (tmp2 <= 0) {
			k = i;
		}
		else {
			wating += tmp2;
		}
	}
	fprintf(out, "%d", wating);

	fclose(inp); fclose(out);
}