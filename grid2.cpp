#include<stdio.h>
#include<stdlib.h>
enum direction {
	R, L, D, U
};
//�ƴϸ� �� �迭�� �ʸ���¥���� ������
int main() {
	FILE * inp = fopen("grid2.inp", "r");
	FILE * oup = fopen("grid2.out", "w");
	int T, N, M, t, s, k, i, re, n, m, j;
	int cnt;
	enum direction dir;
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(inp, "%d %d %d %d %d", &N, &M, &t, &s, &k);

		//���� re�� ��������� �̸� �������� �ʿ������?

		if (s == 1) { //�»�
			m = 0; n = 0; //��� ���� ���۰�0
			re = 1; //���������
			if (t == 3) dir = R; //Ÿ��3 ù����
			else dir = D; //Ÿ��4 ù����
		}
		else if (s == 2) {//���
			m = M - 1; n = 0; //m=M-1�� ������ϳ�?
			re = M;
			if (t == 3) dir = D;
			else dir = L;
		}
		else if (s == 3) { //����
			m = M - 1; n = N - 1;
			re = M * N;
			if (t == 3) dir = L;
			else dir = U;
		}
		else { //����
			m = 0; n = N - 1;
			re = M * N - M + 1;
			if (t == 3) dir = U;
			else dir = R;
		}
		//���� ���� re�� �����س��� �ʿ䰡 ����??

		//ù��° ��ġ�� �κ�, �ι�° ��ġ�ºκ� �̷���
		//����������ϳ�?
		//�̷��� ¥�� �ѿ��� ����ó�� ������
		//�׷��ϱ� n, m�����ؼ� ����Ұ�
		//���������ϱ� ����¥��

		//����ó�� ���� ���ؼ� �ڸ��°� ���
		//���پ�?

		//������ �迭�� �ʸ��� �� �����ڰ�
		//n*m �̷����ؼ�
		//�������� 1�־��ְ� �ϴ°� ���?
		//����Ÿ�Ӷ߷���??

		//���� �ٽ� ���۾�
		//���ù�����...

		//cnt�� �ٽ� �Ẽ��?
		//��� ���鼭
		//�켱 cnt==1�϶���
		//cnt>1 �϶� -> �ι��� �ѹ��� +=(cnt/2)
		//�ƴ��� cnt�� �ٽ� �� �����غ���
		//1 2 3 ���̷��Ÿ��� �� �޶�����
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

		else { //Ÿ��4
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
		
		//����� ����ڷ�
		//re = n * M + m + 1;
		if (i != T - 1) fprintf(oup, "%d\n", re);
		else fprintf(oup, "%d", re);
	}

	fclose(inp); fclose(oup);
}