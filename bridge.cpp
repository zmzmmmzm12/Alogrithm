#include<stdio.h>
#include<string.h>

enum dil { n, e, w, s };
void bubbleSort(int a[], char base[2][13]) {
	for (int i = 0; i < 13; i++) {
		int j;
		for (j = 0; j < 12 - i ; j++) {
			if (a[j] > a[j + 1]) {
				int min = a[j + 1];
				a[j + 1] = a[j];
				a[j] = min;
				int tmp1, tmp2;
				tmp1 = base[0][j]; tmp2 = base[1][j];
				base[0][j] = base[0][j + 1];
				base[1][j] = base[1][j + 1];
				base[0][j + 1] = tmp1;
				base[1][j + 1] = tmp2;
			}
		}
	}
}

void sort(int reN[], char N[2][13]) {
	int i;
	for (i = 0; i < 13; i++) {
		if (N[0][i] == 'C') {
			switch (N[1][i]) {
			case '2': reN[i] = 1; break;
			case '3':reN[i] = 2; break;
			case '4':reN[i] = 3; break;
			case '5':reN[i] = 4; break;
			case '6':reN[i] = 5; break;
			case '7':reN[i] = 6; break;
			case '8':reN[i] = 7; break;
			case '9':reN[i] = 8; break;
			case 'T':reN[i] = 9; break;
			case 'J':reN[i] = 10; break;
			case 'Q':reN[i] = 11; break;
			case 'K':reN[i] = 12; break;
			case 'A':reN[i] = 13; break;
			}
		}
		else if (N[0][i] == 'D') {
			switch (N[1][i]) {
			case '2': reN[i] = 14; break;
			case '3':reN[i] = 15; break;
			case '4':reN[i] = 16; break;
			case '5':reN[i] = 17; break;
			case '6':reN[i] = 18; break;
			case '7':reN[i] = 19; break;
			case '8':reN[i] = 20; break;
			case '9':reN[i] = 21; break;
			case 'T':reN[i] = 22; break;
			case 'J':reN[i] = 23; break;
			case 'Q':reN[i] = 24; break;
			case 'K':reN[i] = 25; break;
			case 'A':reN[i] = 26; break;
			}
		}
		else if (N[0][i] == 'S') {
			switch (N[1][i]) {
			case '2': reN[i] = 27; break;
			case '3':reN[i] = 28; break;
			case '4':reN[i] = 29; break;
			case '5':reN[i] = 30; break;
			case '6':reN[i] = 31; break;
			case '7':reN[i] = 32; break;
			case '8':reN[i] = 33; break;
			case '9':reN[i] = 34; break;
			case 'T':reN[i] = 35; break;
			case 'J':reN[i] = 36; break;
			case 'Q':reN[i] = 37; break;
			case 'K':reN[i] = 38; break;
			case 'A':reN[i] = 39; break;
			}
		}
		else {
			switch (N[1][i]) {
			case '2': reN[i] = 40; break;
			case '3':reN[i] = 41; break;
			case '4':reN[i] = 42; break;
			case '5':reN[i] = 43; break;
			case '6':reN[i] = 44; break;
			case '7':reN[i] = 45; break;
			case '8':reN[i] = 46; break;
			case '9':reN[i] = 47; break;
			case 'T':reN[i] = 48; break;
			case 'J':reN[i] = 49; break;
			case 'Q':reN[i] = 50; break;
			case 'K':reN[i] = 51; break;
			case 'A':reN[i] = 52; break;
			}
		}
	}
}

int main() {
	FILE * inp = fopen("bridge.inp", "r");
	FILE * out = fopen("bridge.out", "w");
	int i;
	char T = 'k';
	enum dil d;
	char a;
	char arr[2][52]; //공백이 들어오면 널 인걸 생각해서
	char S[2][13];
	char W[2][13];
	char N[2][13];
	char E[2][13];
	int reS[13], reW[13], reN[13], reE[13];
	//substr함수를 만들까 
	while (T != '#') {
		fscanf(inp, "%c", &T);
		if (T == '#') break;
		int cntN = 0, cntS = 0, cntE = 0, cntW = 0;
		if (T == 'N')d = e;
		else if (T == 'S') d = w;
		else if (T == 'W')d = n;
		else d = s;
		fscanf(inp, "%c", &a); //공백한번받고
		for (i = 0; i < 52; i++) {
			if (i == 26) fscanf(inp, "%c", &a); //공백한번받고
			fscanf(inp, "%c%c", &arr[0][i], &arr[1][i]);
		}
		for (i = 0; i < 52; i++) {
			if (d == e) {
				E[0][cntE] = arr[0][i];
				E[1][cntE] = arr[1][i];
				cntE++;
				d = s;
			}
			else if (d == s) {
				S[0][cntS] = arr[0][i];
				S[1][cntS] = arr[1][i];
				cntS++;
				d = w;
			}
			else if (d == w) {
				W[0][cntW] = arr[0][i];
				W[1][cntW] = arr[1][i];
				cntW++;
				d = n;
			}
			else {
				N[0][cntN] = arr[0][i];
				N[1][cntN] = arr[1][i];
				cntN++;
				d = e;
			}
		} //넣는 부분 끝. 이제 정렬할 차례
		sort(reN, N);
		sort(reS, S);
		sort(reW, W);
		sort(reE, E);
		 // 앞부분 정렬인데 뒷부분 정렬을 따로 짤지 아니면, 걍 if문에 w[1][i]=='k'이런걸로 우선순위 넣을까? if문에 같이넣고 걍 소스 더럽게짜자!!
		//우선순위가 4*13해서 52까지,,,,,,,?
		//뒷부분 정렬을 따로짜자....우선순위 같은거끼리만 돌려서 오름차순정렬
		//Qsort를 잘짯을까,,,
		bubbleSort(reN, N);
		bubbleSort(reE, E);
		bubbleSort(reS, S);
		bubbleSort(reW, W);
		fprintf(out, "S:");
		for (i = 0; i < 13; i++) {
			fprintf(out, " %c%c", S[0][i], S[1][i]);
			if (i == 12) fprintf(out, "\n");
		}
		fprintf(out, "W:");
		for (i = 0; i < 13; i++) {
			fprintf(out, " %c%c", W[0][i], W[1][i]);

			if (i == 12) fprintf(out, "\n");
		}
		fprintf(out, "N:");
		for (i = 0; i < 13; i++) {
			fprintf(out, " %c%c", N[0][i], N[1][i]);

			if (i == 12) fprintf(out, "\n");
		}
		fprintf(out, "E:");
		for (i = 0; i < 13; i++) {
			fprintf(out, " %c%c", E[0][i], E[1][i]);

			if (i == 12) fprintf(out, "\n");
		}
		fscanf(inp, "%c", &a);
	}
	fclose(inp); fclose(out);
}

