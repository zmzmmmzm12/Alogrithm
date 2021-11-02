#include<stdio.h>

int main() {
	FILE * inp = fopen("line.inp", "r");
	FILE * out = fopen("line.out", "w");
	int T, M, n, cnt, k,mink,maxk, i, j,l,m,x,y,count;
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(inp, "%d", &M);
		x = 0,y=0, cnt=0,count=0;
		mink = -2, maxk = -1;
		for (j = 0; j < M; j++) {
			int q, a;
			if (cnt != 0) {
				while (j < M) {
					fscanf(inp, "%d %d", &q, &a); j++;
				}
				break;
			}
			fscanf(inp, "%d %d", &q, &a);
			for (l = 0; l < 1000000; l++) {
				if (l == 1) x = 1, y=1;
				else if (l >1 ) y=x+1, x += l;
				if (a == l + 1 && l == 0) {
					if (mink <= ((q - x) / a) || mink < 0) {
						mink = 1;
					}
					if (mink == maxk) { cnt = j + 1; break; }
					break;
				}
				if (a == l + 1&&l!=0) {
					if (maxk > ((q - y) / l) || maxk < 0 ) {
							maxk = (q - y) / l;
					}
					if (mink == maxk) { cnt = j+1; break; }
					if (mink <= ((q - x) / a) || mink < 0 ) {
							mink = (q - x) / a;
							if (((q - x) % a) != 0) mink += 1;
					}
					if (mink == maxk) { cnt = j+1; break; }
					break;
				}
			}
		}
		if (mink == maxk) fprintf(out, "%d %d\n", cnt, mink);
		else {
			fprintf(out, "-1\n");
		}
	}
}