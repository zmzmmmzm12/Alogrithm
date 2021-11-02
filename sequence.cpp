#include<stdio.h>

int main() {
	FILE * inp = fopen("sequence.inp", "r");
	FILE * out = fopen("sequence.out", "w");
	long long int c, A,l;
	int  re, i=1;
	while (1) {
		fscanf(inp, "%lld %lld", &c, &l);
		if (c == -1) break;
		re = 1; A = c;
		while (1) {
			if (c % 2 == 0) {
				c /= 2; re++;
			}
			else {
				c = 3 * c + 1;
				re++;
			}
			if (c == 1) break;
			if (c > l) {
				re--;
				break;
			}
		}
		fprintf(out, "Case %d: A = %lld, limit = %lld, number of terms = %d\n", i, A, l, re);
		i++;
	}
	fclose(inp); fclose(out);
}