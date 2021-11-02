#include<stdio.h>

int main() {
	FILE * inp = fopen("divisor.inp", "r");
	FILE * oup = fopen("divisor.out", "w");
	int T, a, b, i, j, k, cnt,re;
	fscanf(inp, "%d", &T);

	for (i = 0; i < T; i++) {
		fscanf(inp, "%d %d", &a, &b);
		re = 0;
		for (j = a; j <= b; j++) {
			k = 1;
			cnt = 0;
			while (k*k <= j) {
				if (j%k == 0) cnt += 2;
				if (k*k == j) cnt -= 1;
				k++;
			}
			if (j%cnt == 0) re++;
		}
		if (i != T - 1)fprintf(oup, "%d\n", re);
		else fprintf(oup, "%d", re);
	}

}
