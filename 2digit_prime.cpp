#include<stdio.h>

//�̿ϼ� �ҽ�



int main() {
	FILE * inp = fopen("2digit_prime.inp", "r");
	FILE * oup = fopen("2digit_prime.out", "w");
	int T, a, b, i, j, k, l, temp, n = 0, re = 0, cnt = 0;
	fscanf(inp, "%d", &T);
	int arr[21] = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	int strarr[7]; //�ʸ����� ���� �ڸ���7
	//int rearr[2][21];
	int result[42];
	int p[] = { 0,0,1,3,6,10,15,21 };


	j = 0;
	/*
	while (j < 21) {
	   rearr[0][j] = arr[j] / 10;
	   rearr[1][j] = arr[j] % 10;
	   j++;
	}
	*/
	for (i = 0; i < T; i++) {
		fscanf(inp, "%d %d", &a, &b);
		if (b <= 10) {
			//���������� ���� ���°� �ִ����� Ȯ���Ұ�
			fprintf(oup, "0\n");
			continue;
		}
		else {
			for (j = a; j <= b; j++) {
				n = 0;
				temp = j;
				while (temp != 0) {
					strarr[n] = temp % 10;
					temp /= 10;
					n++;
				} //���ڸ��� �������
				for (l = 0; l < n; l++) {
					for (k = 0; k < n - l; k++) {
						result[l*n + k - p[l]] = strarr[k] * 10 + strarr[k + l]; cnt++;
						//if (result[k] == result[k + l+1]) result[k + l+1] = 0;
					}
				} //��������� ��� ����� ���� �����µ� �̷��� �ߺ��� ������ �޸����̼� �̿��ؼ� ����س���, �̹� ���� ���ֱ�?
				for (l = 0; l < 21; l++) {
					for (k = 0; k < cnt; k++) {
						if (result[l] == arr[k]) {
							re++; break;
						}
					}
				}
			}
		}
		//printf("%d %d\n", );
	}
	fclose(inp);
	fclose(oup);
}