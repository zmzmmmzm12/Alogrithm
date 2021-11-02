#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector< vector <int> > q;
vector<bool> check_q;
int check[500000], root[500000];
int m, h;

void dfs(int k_) {
	if (check_q[k_]) {
		return;
	}
	check_q[k_] = true;
	for (int i = 0; i < q[k_].size(); i++) {
		int next = q[k_][i];
		if (check_q[next] == false) {
			h++;
			if (h > m) m = h;
			dfs(next);
		}
	}h--;
}

int main() {
	FILE * inp = fopen("family.inp", "r");
	FILE * out = fopen("family.out", "w");
	int T, N, start, end, i, j;
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(inp, "%d", &N);
		int rt = 0, cnt = 0;
		h = 1, m=0;
		q.clear();
		q.resize(N + 1);
		for (j = 0; j < N-1; j++) {
			fscanf(inp, "%d %d", &start, &end);
			q[start].push_back(end);
			root[start] = 1, check[end] = 1;// cnt++;
		}
		check_q = vector<bool>(N + 1, false);
		for (int l = 0; l < N; l++) {
			sort(q[l].begin(), q[l].end());
		}
		for (j = 0; j < 500000; j++) {
			if (check[j] == 0 && root[j]==1) rt = j; 
		}
		dfs(rt);
		fprintf(out, "%d\n", m);
		for (j = 0; j < 500000; j++) {
			check[j] = 0; root[j] = 0;
		}
	}

	fclose(inp); fclose(out);
}