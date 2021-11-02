#include<stdio.h>
#include <algorithm>
//#include<stdlib.h>

int maxheap[10000];
FILE * inp = fopen("add.inp", "r");
FILE * out = fopen("add.out", "w");

int cmp(const void* n1, const void* n2);
int find(int i, int add, int N);

int main() {
	long long int total;
	int i, N, j;
	long long int t;

	while (1) {
		t = 0;
		fscanf(inp, "%d", &N);
		if (N == 0) break;
		int cost = 0;
		//int arr[10000] = { 0, };
		int add;
		for (i = 0; i < N; i++) {
			fscanf(inp, "%d", &maxheap[i]);
		}

		std::sort(maxheap, maxheap + N);
	//	qsort(maxheap, N, sizeof(int), cmp);
		//내림차순 정렬임!!

		for (i = 0; i < N - 1; i++) {
			add = maxheap[i] + maxheap[i + 1];
			t += add;
			maxheap[i] = 0; maxheap[i + 1] = add;
			if (add > maxheap[i + 2])
				std::sort(maxheap + i, maxheap+find(i, add, N)+1);
		}

		fprintf(out, "%lld\n", t);
	}
	fclose(inp); fclose(out);
}

int cmp(const void* n1, const void* n2) {
	int a = *(int*)n1;
	int b = *(int *)n2;
	int tmp;
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

int find(int i, int add, int N) {
	int j = i + 1;
	while (1) {
		if (j == N - 1) break;
		if (add < maxheap[j]) break;
		j++;
	}
	return j;
}