#include<stdio.h>

int main() {
	int T, N; //총 테스트 경우의 수 T, 두 수열에 들어가는 숫자의 갯수N
	int i, j, l;
	int s1[10000],s2[10000];
	int s[2][10000];
	int cnt;
	FILE * inp = fopen("cross.inp", "r");
	FILE * out = fopen("cross.out", "w");
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		cnt = 0;
		fscanf(inp, "%d", &N);
		for (j = 0; j < N; j++) {
			fscanf(inp, "%d", &s1[j]);
		}
		for (j = 0; j < N; j++) {
			fscanf(inp, "%d", &s2[j]);
		}
		for (j = 0; j < N; j++) {
			for (l = 0; l < N; l++) {
				if (s1[j] == s2[l]) {
					s[0][j] = j;
					s[1][j] = l;
				}
			}
		} //index정렬하고
		
		for (j = 0; j < N; j++) {
			for (l = j; l < N; l++) {
				if (s[0][j]<s[0][l]) {
					if (s[1][j] >= s[1][l]) cnt++;
				}
				//if(s[0][j]==s[1][l])
			}
		}
		if(i!=T-1)fprintf(out, "Case %d: %d\n", i + 1, cnt);
		else fprintf(out, "Case %d: %d", i + 1, cnt);
	}



	fclose(inp); fclose(out);
}