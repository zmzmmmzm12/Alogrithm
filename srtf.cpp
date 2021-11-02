#include<stdio.h>
#include<stdlib.h>

typedef struct process {
	int number, arrive, cpu, wating, stop;
}process;

int compare(const void * a1, const void * b1) {
	process * a = (process *)a1;
	process * b = (process *)b1;
	if (a->arrive < b->arrive) return -1;
	else if (a->arrive == b->arrive) {
		if (a->number < b->number) {
			return -1;
		}
		else {
			return 1;
		}
	}
	else return 1;
}

int main() {
	FILE * inp = fopen("srtf.inp", "r");
	FILE * out = fopen("srtf.out", "w");
	int n, time, re = 0, m, min, t;
	fscanf(inp, "%d", &n);
	process * rq = (process*)malloc(sizeof(process)*n);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d %d %d", &rq[i].number, &rq[i].arrive, &rq[i].cpu);
		rq[i].stop = rq[i].cpu;
		rq[i].wating = 0;
	}
	qsort(rq, n, sizeof(process), compare);
	m = n;
	time = rq[0].arrive;
	while (m > 0) {
		min = 900000;
		for (int i = 0; i < n && rq[i].arrive <= time; i++) {
			if (rq[i].stop < min) {
				if (rq[i].stop > 0) {
					min = rq[i].stop;
					t = i;
				}
			}
		}
		time++;
		rq[t].stop--;
		if (rq[t].stop == 0) {
			rq[t].wating = time - rq[t].arrive - rq[t].cpu;
			m--;
		}
	}
	for (int i = 0; i < n; i++) {
		re += rq[i].wating;
	}
	fprintf(out, "%d", re);
	fclose(inp); fclose(out);
}