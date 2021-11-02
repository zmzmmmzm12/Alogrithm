#include <iostream>
#include<stdio.h>
using namespace std;
int arr[100001];

int div_sum(int arr);
int div_sh(int num);

int main() {
	FILE * inp = fopen("primefactor.inp", "r");
	FILE * out = fopen("primefactor.out", "w");
	int T, N, i;
	fscanf(inp, "%d", &T);
	for (i = 1; i <= T; i++) {
		fscanf(inp, "%d", &N);
		if (div_sh(N) == -1) fprintf(out, "Prime Number\n");
		else fprintf(out, "%d\n", div_sum(N));
	}
	fclose(inp); fclose(out);
}

int div_sum(int arr) {
	int sum = 0, i;
	for (i = 2;;) {
		if (arr == 1)break;
		if (arr % i == 0) {
			arr /= i;
			sum += i;
		}
		else {
			i++;
		}
	}
	return sum;
}

int div_sh(int num) {
	int i, j;
	for (i = 0; i <= num; i++)arr[i] = -1;
	for (i = 2; i <= num; i++) {
		for (j = i + i; j <= num; j += i) {
			arr[j] = j;
		}
	}
	if (arr[num] == -1)return -1;
	else return num;
}