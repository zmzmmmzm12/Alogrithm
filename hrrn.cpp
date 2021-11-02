#include<stdio.h>
#include<stdlib.h>

typedef struct process {
	int number, arrive, cpu, wating, t;
}process;

void bubbleSort(process * pro, int N) {
	//첫 정렬
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (pro[j].arrive > pro[j+1].arrive) {
				process tmp = pro[j];
				pro[j] = pro[j + 1];
				pro[j + 1] = tmp;
			}
			if (pro[j].arrive == pro[j+1].arrive) { //도착시간동일
				if (pro[j].number > pro[j+1].number) { //프로세스 번호 작은거부터 실행
					process tmp = pro[j];
					pro[j] = pro[j + 1];
					pro[j + 1] = tmp;
				}
			}
		}
	}
}

void sort(process * pro, int d, int f) {
	//우선순위 기준으로 정렬할것
	for (int i = d; i < f; i++) {
		for (int j = d; j < f - 1; j++) {
			double b0, b1;
			//대기시간을 알아야하는디
			b0 = (pro[j].wating + pro[j].cpu)*1.0 / pro[j].cpu;
			b1 = (pro[j+1].wating + pro[j+1].cpu)*1.0 / pro[j+1].cpu;
			if (b0 < b1) {
				process tmp = pro[j];
				pro[j] = pro[j + 1];
				pro[j + 1] = tmp;
			}
			else if (b0 == b1) {
				if (pro[j].arrive > pro[j + 1].arrive) {
					process tmp = pro[j];
					pro[j] = pro[j + 1];
					pro[j + 1] = tmp;
				}
				else if (pro[j].arrive == pro[j + 1].arrive) {
					if (pro[j].number > pro[j + 1].number) {
						process tmp = pro[j];
						pro[j] = pro[j + 1];
						pro[j + 1] = tmp;
					}
				}
			}
		}
	}
}


int main() {
	FILE * inp = fopen("hrrn.inp", "r");
	FILE * out = fopen("hrrn.out", "w");
	int n;
	int i, j, k = 0, l, tmp, tmp1, tmp2, re=0;
	fscanf(inp, "%d", &n);
	process * rq = (process*)malloc(sizeof(process)*n);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d %d %d", &rq[i].number, &rq[i].arrive, &rq[i].cpu);
	}
	bubbleSort(rq, n);
	for (int i = 1; i < n; i++) {
		tmp = rq[k].arrive;
		for (j = k; j < i; j++) {
			tmp += rq[j].cpu;
		}
		if ((rq[i].arrive - tmp) > 0) {
			tmp += (rq[i].arrive - tmp);
			k = i;
		}
		for (l = i; l < n; l++) {
			if (rq[l].arrive > tmp) {
				break;
			}
			rq[l].wating = tmp - rq[l].arrive;
		}
		sort(rq, i, l);
	}

	k = 0;
	for (i = 1; i < n; i++) {
		tmp1 = 0;
		for (j = k; j < i; j++) {
			tmp1 += rq[j].cpu;
		}
		tmp2 = tmp1 - rq[i].arrive + rq[k].arrive;
		if (tmp2 <= 0) {
			k = i;
		}
		else {
			re += tmp2;
		}
	}

	fprintf(out, "%d", re);

	fclose(inp); fclose(out);
}