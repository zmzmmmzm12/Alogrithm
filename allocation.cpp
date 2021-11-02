#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

FILE * inp = fopen("allocation.inp", "r");
FILE * out = fopen("allocation.out", "w");

int n, timer, pointer, mindex;

struct list {
	int num, inTime, outTime, start, size;
};

struct list2 {
	int processnum, sindex, eindex;
};

vector <list> process, rq, node;
vector <list2> memory;
list pinsert;

int cmp(const list2 &x1, const list2 &x2) {
	if (x1.sindex < x2.sindex) return 1;
	else return 0;
}

void insert() {
	list tmp;
	int startT, useT, Alloc;
	fscanf(inp, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d %d %d", &startT, &useT, &Alloc);
		tmp.num = i, tmp.inTime = startT;
		tmp.outTime = startT + useT;
		tmp.size = Alloc;
		process.push_back(tmp);
	}
}

void insertM(list P, int i) {
	list2 state;

	P.start = memory[i].sindex;
	P.outTime = P.outTime - P.inTime + timer;
	P.inTime = timer;

	state.processnum = P.num;
	state.sindex = memory[i].sindex;
	state.eindex = P.start + P.size;
	memory[i].sindex = state.eindex;

	memory.push_back(state);
	node.push_back(P);
	pinsert = P;

	if (memory[i].eindex == memory[i].sindex) memory.erase(memory.begin() + i);
	sort(memory.begin(), memory.begin() + memory.size(), cmp);
}

void sumM(int index) {
	if (index > 0) {
		if (memory[index - 1].processnum == -1) {
			memory[index - 1].eindex = memory[index].eindex;
			memory.erase(memory.begin() + index);
			index--;
		}
	}
	if (index < memory.size() - 1) {
		if (memory[index + 1].processnum == -1) {
			memory[index].eindex = memory[index + 1].eindex;
			memory.erase(memory.begin() + index + 1);
		}
	}
	if (memory[index].eindex == memory[index].sindex) memory.erase(memory.begin() + index);
}

void releaseM(int index) {
	list releaseP = node[index];

	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].processnum == releaseP.num) {
			memory[i].processnum = -1;
			sumM(i);
			break;
		}
	}
	node.erase(node.begin() + index);
}

int isMInsert(list P, int type) {
	int mSize = memory.size();
	int i, h, d, di = -1;
	if (type == 2) d = 999999;
	else if (type == 3) d = -999999;

	for (i = 0; i < mSize; i++) {
		h = memory[i].eindex - memory[i].sindex;
		if (type == 1) {
			if (P.size <= h && memory[i].processnum == -1) {
				mindex = i;
				return 1;
			}
		}
		else if (type == 2) {
			if (P.size <= h && memory[i].processnum == -1) {
				if (d > h - P.size) {
					d = h - P.size;
					di = i;
					mindex = i;
				}
			}
		}
		else {
			if (P.size <= h && memory[i].processnum == -1) {
				if (d < h - P.size) {
					d = h - P.size;
					di = i;
					mindex = i;
				}
			}
		}
	}
	if (di != -1) return 1;
	else return 0;
}

int isInsert(int type) {
	if (pointer == n) return 0;
	if (process[pointer].inTime > timer) return 0;
	list insertPro = process[pointer++];

	if (isMInsert(insertPro, type)==1) {
		insertM(insertPro, mindex);
	}
	else {
		rq.push_back(insertPro);
	}
	return 1;
}

void insertQ(int type) {
	for (int i = 0; i < rq.size(); i++) {
		if (isMInsert(rq[i], type)==1) {
			insertM(rq[i], mindex);
			rq.erase(rq.begin() + i);
			i--;
		}
	}
}

void set() {
	list2 tmp;
	pinsert.num = -1, timer = 0, pointer = 0;
	memory.clear();
	node.clear();
	rq.clear();
	tmp.processnum = -1, tmp.sindex = 0, tmp.eindex = 1000;
	memory.push_back(tmp);
}

int isRelease() {
	int ret = 0;
	for (int i = 0; i < node.size(); i++) {
		if (node[i].outTime <= timer) {
			releaseM(i);
			ret = 1;
			i--;
		}
	}
	return ret;
}

void setFit(int type) {
	set();
	while (pinsert.num != n - 1) {
		if (isRelease()==1) {
			insertQ(type);
		}
		while (isInsert(type)==1);
		timer++;
	}
	fprintf(out, "%d\n", pinsert.start);
}

int main() {
	insert();
	setFit(1);//First
	setFit(2);//Best
	setFit(3);//Worst

	fclose(inp), fclose(out);
}