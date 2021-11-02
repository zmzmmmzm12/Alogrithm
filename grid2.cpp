#include<stdio.h>
#include<stdlib.h>
enum direction {
	R, L, D, U
};
//아니면 걍 배열을 십만개짜리를 박을까
int main() {
	FILE * inp = fopen("grid2.inp", "r");
	FILE * oup = fopen("grid2.out", "w");
	int T, N, M, t, s, k, i, re, n, m, j;
	int cnt;
	enum direction dir;
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(inp, "%d %d %d %d %d", &N, &M, &t, &s, &k);

		//굳이 re를 결과값으로 미리 만들어놓을 필요없겠지?

		if (s == 1) { //좌상
			m = 0; n = 0; //행과 열의 시작값0
			re = 1; //결과값설정
			if (t == 3) dir = R; //타입3 첫방향
			else dir = D; //타입4 첫방향
		}
		else if (s == 2) {//우상
			m = M - 1; n = 0; //m=M-1로 해줘야하나?
			re = M;
			if (t == 3) dir = D;
			else dir = L;
		}
		else if (s == 3) { //우하
			m = M - 1; n = N - 1;
			re = M * N;
			if (t == 3) dir = L;
			else dir = U;
		}
		else { //좌하
			m = 0; n = N - 1;
			re = M * N - M + 1;
			if (t == 3) dir = U;
			else dir = R;
		}
		//굳이 내가 re를 선언해놓을 필요가 없나??

		//첫번째 겹치는 부분, 두번째 겹치는부분 이런거
		//생각해줘야하나?
		//이렇게 짜면 겉에만 액자처럼 빙빙돔
		//그러니까 n, m선언해서 계산할것
		//실패했으니까 새로짜자

		//액자처럼 단위 정해서 자르는건 어떨까
		//한줄씩?

		//일차원 배열에 십만개 다 때려박고
		//n*m 이런거해서
		//들어갈때마다 1넣어주고 하는건 어떨까?
		//오버타임뜨려나??

		//이제 다시 시작쓰
		//열시미하자...

		//cnt를 다시 써볼까?
		//계속 돌면서
		//우선 cnt==1일때와
		//cnt>1 일때 -> 두번에 한번씩 +=(cnt/2)
		//아니지 cnt를 다시 또 생각해보면
		//1 2 3 뭐이런거마다 다 달라지고
		cnt = 0;
		if (t == 3) {
			//for (j = 1; j < k; j++) {
			while(k>1){
				if (dir == R) {
					if (cnt < 3) { //or 1 or3
						if (m >= M - 1) {
							if(cnt==2) n++; 
							dir = D; cnt++;
						}
						else m++, re+=1, k--;
					}
					else {
						if (m >= M - 1) {
							
							n+=(cnt/2); dir = D; cnt++;
						}
						else m++,re+=1, k--;
					}
				}

				else if (dir == L) {
					if (cnt < 3) { //or 1 or3
						if (m < 1) {
							if (cnt == 2) n--;
							dir = U; cnt++;
						}
						else m--,re-=1, k--;
					}
					else {
						if (m < 1) {
							
							n -= (cnt / 2); dir = U; cnt++;
						}
						else m--,re-=1, k--;
					}
				}

				else if (dir == D) {
					if (cnt < 3) { //or 1 or3
						if (n>=N-1) {
							if (cnt == 2)m--;
							dir = L; cnt++;
						}
						else  n++,re+=M, k--;
					}
					else {
						if (n>=N-1) {
							
							m -= (cnt / 2); dir = L; cnt++;
						}
						else n++,re+=M, k--;
					}
				}

				else {//dir==U
					if (cnt < 3) { //or 1 or3
						if (n<1) {
							if (cnt == 2) m++;
							dir = R; cnt++;
						}
						else  n--,re-=M, k--;
					}
					else {
						if (n < 1) {
							
							m += (cnt / 2); dir = R; cnt++;
						}
						else n--,re-=M, k--;
					}
				}
			}
		}

		else { //타입4
			while (k > 1) {
				if (dir == R) {
					if (cnt < 3) { //or 1 or3
						if (m >= M - 1) {
							if (cnt == 2) n--;
							dir = U; cnt++;
						}
						else m++, re += 1, k--;
					}
					else {
						if (m >= M - 1) {

							n -= (cnt / 2); dir = U; cnt++;
						}
						else m++, re += 1, k--;
					}
				}

				else if (dir == L) {
					if (cnt < 3) { //or 1 or3
						if (m < 1) {
							if (cnt == 2) n++;
							dir = D; cnt++;
						}
						else m--, re -= 1, k--;
					}
					else {
						if (m < 1) {

							n += (cnt / 2); dir = D; cnt++;
						}
						else m--, re -= 1, k--;
					}
				}

				else if (dir == D) {
					if (cnt < 3) { //or 1 or3
						if (n >= N - 1) {
							if (cnt == 2)m++;
							dir = R; cnt++;
						}
						else  n++, re += M, k--;
					}
					else {
						if (n >= N - 1) {

							m += (cnt / 2); dir = R; cnt++;
						}
						else n++, re += M, k--;
					}
				}

				else {//dir==U
					if (cnt < 3) { //or 1 or3
						if (n < 1) {
							if (cnt == 2) m--;
							dir = L; cnt++;
						}
						else  n--, re -= M, k--;
					}
					else {
						if (n < 1) {

							m -= (cnt / 2); dir = L; cnt++;
						}
						else n--, re -= M, k--;
					}
				}
			}
			
		}
		
		//결과는 요로코롬
		//re = n * M + m + 1;
		if (i != T - 1) fprintf(oup, "%d\n", re);
		else fprintf(oup, "%d", re);
	}

	fclose(inp); fclose(oup);
}