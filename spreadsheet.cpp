#include<stdio.h>

int mul(int a) {
	int k=1;
	for (int i = 0; i < a; i++)
		k *= 26;
	return k;
}

int main() {
	FILE * inp = fopen("spreadsheet.inp", "r");
	FILE * out = fopen("spreadsheet.out", "w");
	int N, i,j, cntr, cnt, row,k,col,cntl,index,m,l,p,a,y,cntk;
	char abc[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char z;
	fscanf(inp, "%d", &N);
	for (i = 0; i < N; i++) {
		cntk = 0,cntl=0;
		j = 0;
		cntr = 0; cnt = 0,row=0,col=0,k=1,index=0,a=0,y=0;
		char re[17] = { '\0', };
		char e[17] = { '\0', };
		int o[17] = { '\0,' };
		p = 0;
		if(i==0) fscanf(inp, "%c", &z);
		while(fscanf(inp, "%c", &z)!=EOF){
			if (z == '\n') break;
			re[j] = z;
			if (re[0] == 'R') if (re[j] == 'C'&&re[j-1]<='9') cnt = j - 1;
			j++; //문자열의 길이
		}
		if (cnt!=0) {// R일때
			for (l = cnt; l > 0; l--) {
				row += (re[l]-'0') * k;
				k *= 10;
				//cntl++;
			} //row은 행의 값이
			k = 1;
			for (l = j-1; l > cnt + 1; l--) {
				col += (re[l]-'0') * k;
				k *= 10;
				//cntk++;
			} //col은 열의 값이 들어옴
			y = col;
			if (col <= 26) cntk = 1;
			else if (col <= 702) cntk = 2;
			else if (col <= 18278) cntk = 3;
			else if (col <= 475254) cntk = 4;
			else cntk = 5;
			a = cntk - 1;
			for (m = 0; m < cntk; m++) {
				//마지막 글자가 Z일때를 생각해주기!
				if (m != cntk - 1) {
					o[m] = y / mul(a);
					if (o[m] == 0) {
						o[m-1] -= 1;
						o[m] = 26;
					}
					else {
						y -= (o[m] * mul(a));
					}
					a--;
				}
				else {
					if (y == 0) {
						o[m - 1] -= 1;
						o[m] = 26;
						if (o[m - 1] == 0) {
							//2말고 쭉 cntk까지 해줘야하나??
							o[m - 2] -= 1;
							o[m - 1] = 26;
						}
					}
					else o[m] = y;
				}
			}
			for (m = 0; m < cntk; m++) {
				for (l = 1; l <= 26; l++) {
					if (o[m] == l) {
						e[m] = abc[l - 1];
						break;
					}
				}
				fprintf(out, "%c", e[m]);
			}
			fprintf(out, "%d\n", row);

		}
		else { //엑셀
			for (l = 0; l < j; l++) {
				if (re[l] > '0'&&re[l] <= '9') {
					cnt = l - 1; break;
				}
			}
			for (l = j-1; l > cnt; l--) {
				row += (re[l]-'0') * k;
				k *= 10;
			} //row은 행의 값이
			for (l = cnt; l >= 0; l--) {
				for (m = 0; m < 26; m++) {
					if (re[l] == abc[m]) {
						p += (mul(a)*(m+1));
						a++;
					}
				}
			}
			fprintf(out, "R%dC%d\n", row, p);
		}
	}
	fclose(inp); fclose(out);
}