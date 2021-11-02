#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct jumi
{
	int value;
	int point;
};

vector< vector <jumi> > q;
vector<bool> check;
int re_d, re_b;

bool cmp(const jumi &p1, const jumi &p2) {
	return p1.point < p2.point;
}

void dfs(int k_) {
	if (check[k_]) return;
	check[k_] = true;
	for (int i = 0; i < q[k_].size(); i++) {
		int next = q[k_][i].point;
		if (check[next] == false) {
			re_d += q[k_][i].value;
			dfs(next);
		}
	}
}

void bfs(int k_) {
	queue<int> qsearch;
	check[k_] = true;
	qsearch.push(k_);
	while (!qsearch.empty()) {
		int front = qsearch.front();
		qsearch.pop();
		for (int i = 0; i < q[front].size(); i++) {
			int next = q[front][i].point;
			if (check[next] == false) {
				re_b += q[front][i].value;
				qsearch.push(next);
				check[next] = true;
			}
		}
	}
}

int main() {
	FILE * inp = fopen("graph.inp", "r");
	FILE * out = fopen("graph.out", "w");
	int  n, m, u, v, w, i, j, T, k, k_;
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(inp, "%d %d", &n, &m);
		q.clear();
		q.resize(n + 1);
		//벡터 초기화가 안되는거 같은데~
		for (j = 0; j < m; j++) {
			fscanf(inp, "%d %d %d", &u, &v, &w);
			jumi ju;
			ju.value = w;
			ju.point = v;
			q[u].push_back(ju);
			ju.point = u;
			q[v].push_back(ju);
		}
		fscanf(inp, "%d", &k);
		for (j = 0; j < k; j++) {
			fscanf(inp, "%d", &k_);
			check = vector<bool>(n + 1, false);
			for (int l = 0; l < n; l++) {
				sort(q[l].begin(), q[l].end(),cmp);
			}
			dfs(k_);
			check = vector<bool>(n + 1, false);
			bfs(k_);
			fprintf(out, "n=%d m=%d start=%d DFS:%d BFS:%d\n", n, m, k_, re_d, re_b);
			re_d = 0, re_b = 0;
		}
	}
	fclose(inp); fclose(out);
}