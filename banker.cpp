#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>

using namespace std;
FILE * inp = fopen("banker.inp", "r");
FILE * out = fopen("banker.out", "w");
int n, m;
int alloc[52], total[52];

struct sl {
	int qn;
	int qre[52], res[52], max[52], req[52];
};

vector<sl> process, rq;

bool exec(vector<sl> sim, int reqPro, int allocsm[]) { //process의 요구 수행 가능?
	for (int i = 0; i < m; i++) {
		if (allocsm[i] - sim[reqPro].req[i] < 0) {
			return false;
		}
	}
	return true;
}

bool safe(int reqPro, int reqRes[]) { //모름지기 안전이 중요한법
	vector<sl> sim;
	int cnt = 0;
	int allocsm[52];
	sl tmp;
	for (int i = 0; i < process.size(); i++) {
		tmp = process[i];
		sim.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		allocsm[i] = alloc[i];
	}
	for (int i = 0; i < m; i++) {
		allocsm[i] -= reqRes[i];
		sim[reqPro].res[i] += reqRes[i];
		sim[reqPro].req[i] -= reqRes[i];
		if (allocsm[i] < 0) {
			return false;
		}
	}
	for (int i = 0; !(cnt > sim.size() + 1 || sim.empty()); i++) {
		if (exec(sim, i%sim.size(), allocsm)) {
			for (int j = 0; j < m; j++) {
				allocsm[j] += sim[i%sim.size()].max[j];
			}
			cnt = 0;
			sim.erase(sim.begin() + (i%sim.size()));
			i--;
		}
		cnt++;
	}
	if (sim.empty()) {
		return true;
	}
	else return false;
}

void search() { //찾자
	int reqRes[52];
	bool plus;
	for (int i = 0; i < rq.size(); i++) {
		plus = false;
		for (int j = 0; j < m; j++) {
			reqRes[j] = rq[i].qre[j];
		}
		if (safe(rq[i].qn, reqRes)) {
			int pn = rq[i].qn;
			for (int k = 0; k < m; k++) {
				if (process[pn].res[k] + reqRes[k] > process[pn].max[k]) {
					plus = true;
				}
			}
			if (plus) {
				continue;
			}
			for (int k = 0; k < m; k++) {
				alloc[k] -= reqRes[k];
				process[pn].res[k] += reqRes[k];
				process[pn].req[k] = process[pn].max[k] - process[pn].res[k];
			}
			rq.erase(rq.begin() + i);
			i--;
		}
	}
	return;
}

void release() { //다씀
	int relRes[52], relPro;
	fscanf(inp, "%d", &relPro);
	for (int i = 0; i < m; i++) {
		fscanf(inp, "%d", &relRes[i]);
		alloc[i] += relRes[i];
		process[relPro].res[i] -= relRes[i];
		process[relPro].req[i] = process[relPro].max[i] - process[relPro].res[i];
	}
	search();
	return;
}

bool request() { //자원을 할당해달라
	int reqPro;
	int reqRes[52];
	fscanf(inp, "%d", &reqPro);
	for (int i = 0; i < m; i++) {
		fscanf(inp, "%d", &reqRes[i]);
		if (total[i] < reqRes[i]) {
			return false;
		}
	}
	if (safe(reqPro, reqRes)) {
		for (int i = 0; i < m; i++) {
			process[reqPro].res[i] += reqRes[i];
			process[reqPro].req[i] = process[reqPro].max[i] - process[reqPro].res[i];
			alloc[i] -= reqRes[i];
		}
	}
	else {
		process[reqPro].qn = reqPro;
		for (int i = 0; i < m; i++) {
			process[reqPro].qre[i] = reqRes[i];
		}
		rq.push_back(process[reqPro]);
	}
	return true;
}

void result() { //끝
	char c[20];
	while (true) {
		fscanf(inp, "%s", c);
		if (strcmp(c,"request")==0) {
			if (!request()) continue;
		}
		else if (strcmp(c, "release") == 0) {
			release();
		}
		else if (strcmp(c, "quit") == 0) {
			return;
		}
		for (int i = 0; i < m; i++) {
			fprintf(out, "%d ", alloc[i]);
		}
		fprintf(out, "\n");
	}
	return;
}

int main() {
	sl tmp;
	int i, j;
	fscanf(inp, "%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		fscanf(inp, "%d", &total[i]);
		alloc[i] = total[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(inp, "%d", &tmp.max[j]);
		}
		process.push_back(tmp);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(inp, "%d", &process[i].res[j]);
			process[i].req[j] = process[i].max[j] - process[i].res[j];
			alloc[j] -= process[i].res[j];
		}
	}
	result();
	fclose(inp), fclose(out);
	return 0;
}