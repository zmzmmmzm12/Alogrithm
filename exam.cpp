#include<stdio.h>
#include<string.h>

void print(FILE * oup, int b) {

}

int main() {
	FILE * inp = fopen("exam.inp", "r");
	FILE * oup = fopen("exam.out", "w");
	int i, j, l, m; //반복문돌릴변수
	int cnt, cntP, cntnQ, cntQ;
	int k, index_p, index_Q;
	int T; //총 테스트케이스의 수
	char arr[26]; //좋은 문자의 집합을 받을 arr
	char p[1000]; //문자열 패턴
	int n; //질의어의 수
	char Q[1000]; //질의어 문자열


	fscanf(inp, "%d", &T);

	for (i = 0; i < T; i++) {
		fscanf(inp, "%s", &arr); //좋은문자집합
		fscanf(inp, "%s", &p);//패턴
		fscanf(inp, "%d", &n);//질의어 수
		fprintf(oup, "Test Case: #%d\n", i);
		for (j = 0; j < n; j++) {
			cnt = 0; cntP = 0; cntnQ = 0, cntQ = 0;
			fscanf(inp, "%s", &Q); //질의어문자열
			//이중 포문으로 짜자
			//l까지 넣어서 짜도 괜찮으려나?
			//어떻게 짤지 다시 생각.
			//for문을 바꾸던지 !!
		//	for (k = 0; k < strlen(p); k++) {
				for (l = 0; l < strlen(Q); l++) {
					if (p[l] != Q[l]) { //만약 두 문자가 다르면
						cnt++; //마지막에 cnt==cntP+cntQ인지 보기
						if (p[l] == '?') { //?일때
							for (m = 0; m < strlen(arr); m++) {
								if (Q[l] == arr[m]) { //좋은문자인지 확인
									cntP++; break; //맞으면 브레이크
								}
							}
						}
						else if (p[l] == '*') { //*일때
							//*뒤에서부터 *까지 읽기
							k = l; //*의 index
							index_p = strlen(p) - 1;
							index_Q = strlen(Q) - 1;
							int o = index_p;
							for (o; o >= 0; o--) {

							}
						}
						else {
						}

					}

				} //for l

			//}//for k

		}//for j

	} //for i


	fclose(inp); fclose(oup);
}