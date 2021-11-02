#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process {
	int iook, total, pn, arrive, bi, rmaks; //그만 괴롭혀라ㅏㅏㅏㅏㅏ
	int cpu[101];
}process;

typedef struct array {
	int start, end, m;
	process array[1000];
}pro;

pro rq, p;

void inq(process p, pro *q) {
	q->array[(q->end + 1) % 101] = p;
	q->end++;
	q->m++;
}

process deq(pro *q) {
	process re = q->array[(q->start + 1) % 101];
	memset(&q->array[(q->start + 1) % 101], 0, sizeof(q->array[(q->start + 1) % 101]));
	q->start++;
	q->m--;
	return re;
}

int main() {
	FILE * inp = fopen("rr.inp", "r");
	FILE * out = fopen("rr.out", "w");
	int n, q, i, j;

	memset(&rq, 0, sizeof(pro));
	memset(&p, 0, sizeof(pro));
	rq.start = -1, rq.end = -1, p.start = -1, p.end = -1;
	memset(rq.array, 0, sizeof(rq.array));
	memset(p.array, 0, sizeof(p.array));

	fscanf(inp, "%d %d", &n, &q);

	for (i = 1; i <= n; i++) {
		p.array[i].pn = i;
		fscanf(inp, "%d %d", &p.array[i].arrive, &p.array[i].rmaks);
		for (j = 0; j < p.array[i].rmaks; j++) {
			fscanf(inp, "%d", &p.array[i].cpu[j]);
		}
	}

	int cnt = 0, mo = 0, ts = q;
	process np;
	memset(&np, 0, sizeof(np));

	while (cnt < n) {
		for (i = 1; i <= n; i++) {
			if (p.array[i].arrive == mo) inq(p.array[i], &rq);
		}
		for (i = 1; i <= n; i++) {
			if (p.array[i].iook == mo && mo > 0) {
				p.array[i].bi++;
				inq(p.array[i], &rq);
			}
		}
		if (ts == 0) {
			if (np.cpu[np.bi] > 0) {
				inq(np, &rq);
				p.array[np.pn].bi = np.bi;
				memset(&np, 0, sizeof(np));
			}
		}
		if (np.pn != 0){
			if (np.cpu[np.bi] == 0) {
				if (mo > 0) {
					np.bi++;
					if (np.bi == np.rmaks) {
						p.array[np.pn].total = mo, cnt++;
					}
					else {
						p.array[np.pn].iook = mo + p.array[np.pn].cpu[np.bi];
						p.array[np.pn].bi = np.bi;
					}
					memset(&np, 0, sizeof(np));
				}
			}
		}
		if (np.pn == 0){
			if (rq.m > 0) {
				np = deq(&rq);
				ts = q;
			}
		}
		mo++, ts--;
		np.cpu[np.bi]--;
	} //while

	for (i = 1; i <= n; i++) {
		int t = p.array[i].total - p.array[i].arrive;
		int b = 0;
		for (j = 0; j < p.array[i].rmaks; j++) {
			b += p.array[i].cpu[j];
		}
		fprintf(out, "%d %d\n", i, t - b);
	}

	fclose(inp), fclose(out);
	return 0;
}
