#include<stdio.h>

int main() {
	FILE * inp = fopen("fraction.inp", "r");
	FILE * out = fopen("fraction.out", "w");
	int k = 1, x, y, cnt,i, re=1, c,d;
	while (k != 0) {
		cnt = 0; re = 1;
		fscanf(inp, "%d", &k);
		if (k == 0) break;
		for (i = k+1; i <= k*2; i++) {
			if (i*k%re==0) cnt++;
			re++;
		}
		fprintf(out, "%d\n", cnt);
	}
	fclose(inp); fclose(out);
}