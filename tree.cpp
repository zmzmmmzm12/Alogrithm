#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int check[1000000], root[1000000];

int main() {
	FILE * inp = fopen("tree.inp", "r");
	FILE * out = fopen("tree.out", "w");
	int node, edge, i = 1, j;
	while (1) {
		int rt = 0, error = 0, cnt = 0, error_root=0;
		while (1) {
			fscanf(inp, "%d %d", &node, &edge);
			if (node == -1 && edge == -1) return 0;
			if (node == 0 && edge == 0) break;
			root[cnt] = node, check[cnt] = edge;
			cnt++;
		}
		sort(&root[0], &root[cnt]); sort(&check[0], &check[cnt]);
		for (j = 0; j < cnt - 1; j++) {
			if (check[j] == check[j + 1]) {
				error = 1; break;
			}
		}
		if(error==1) fprintf(out, "Test Case %d: -1\n", i);
		else {
			int rtcnt = 0, chcnt = 0;
			while (rtcnt < cnt) {
				if (root[rtcnt] == root[rtcnt + 1]) {
					rtcnt++; continue;
				}
				if (check[chcnt] < root[rtcnt]) chcnt++;
				else if (check[chcnt] == root[rtcnt]) chcnt++, rtcnt++;
				else error_root++, rt = root[rtcnt], rtcnt++;
			}
			if(error_root!=1) fprintf(out, "Test Case %d: -1\n", i);
			else fprintf(out, "Test Case %d: %d\n", i, rt);
		}
		i++;
		for (j = 0; j < cnt; j++) {
			check[j] = 0, root[j] = 0;
		}
	}
	fclose(inp); fclose(out);
}