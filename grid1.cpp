#include<stdio.h>

int main() {
	FILE * inp = fopen("grid1.inp", "r");
	FILE * oup = fopen("grid1.out", "w");
	int T, N, M, t, s, k, i, move, re;

	//�׽�Ʈ���̽�T, �� ������ ��N, ��M, Ÿ��t(1or2), �����s(1,2,3,4), �̵��Ÿ�k

	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		//int move, re;
		fscanf(inp, "%d %d %d %d %d", &N, &M, &t, &s, &k);

		if (t == 1) { //Ÿ���� 1�϶�
			move = k / M;
			if (s == 1) { //������ġ�� �»�
				if (move % 2 == 0) {
					if (k%M == 0) {
						if (move == 0) re = k;
						else re = (move)*M - M + 1;
					}
					else re = k;
				} //move�� ¦���̸� �������� k
				else {
					if (k%M == 0)re = k;
					else re = (move + 1)* M - k % M + 1;
				} //Ȧ���̸� ���� �࿡�� ����
			}
			else if (s == 2) { //������ġ�� ���
				if (move % 2 != 0) {
					if (k%M == 0) re = move * M - M + 1;
					else re = k;
				}
				else {
					if (k%M == 0) re = k;
					else re = (move + 1)*M - k % M + 1;
				}
			}
			else if (s == 3) { //������ġ�� ����
				if (move % 2 != 0) {
					if (k%M == 0) re = M * N - k + 1;
					else re = M * N - move * M - (M - k % M);
				}
				else {
					if (k%M == 0) re = M * N - M * (move - 1);
					else re = M * N - move * M - k % M + 1;
				}
			}
			else { //������ġ�� ����. s==4
				if (move % 2 != 0) {
					if (k%M == 0) {
						if (k == M)re = M * N;
						else re = M * N - M * (move - 1);
					}
					else re = M * N - k + 1;
				}
				else {
					if (k%M == 0) re = M * N - k + 1;
					else re = M*N-move*M-(M-k%M);
				}
			}

		}
		else { //Ÿ���� 2�϶� t==2.
			move = k / N;
			if (s == 1) { //������ġ�� �»�
				if (move % 2 != 0) {
					if (k%N == 0) re = move + M * (N - 1);
					else re = move + 1 + M*(N-k%N);
				}
				else {
					if (k%N == 0) re = move;
					else re = move + 1 + M * (k%N - 1);
				}
			}
			else if (s == 2) { //������ġ�� ���
				if (move % 2 != 0) {
					if (k%N == 0) re = M * N - move + 1;
					else re = M * N - move - M * (k%N - 1);
				}
				else {
					if (k%N == 0) re = M - move + 1;
					else re = M - move + M * (k%N - 1);
				}
			}
			else if (s == 3) { //������ġ�� ����
				if (move % 2 != 0) {
					if (k%N == 0) re = M - move + 1;
					else re = M - move + M * (k%N - 1);
				}
				else {
					if (k%N == 0) re = M * N - move + 1;
					else re = M * N - move - M * (k%N - 1);
				}
			}
			else { //������ġ�� ����. s==4
				if (move % 2 != 0) {
					if (k%N == 0) re = move;
					else re = move + 1 + M * (k%N - 1);
				}
				else {
					if (k%N == 0) re = move + M * (N - 1);
					else re = move + 1 + M*(N-k%N);
				}
			}
		}
		if (i != T - 1) fprintf(oup, "%d\n", re);
		else fprintf(oup, "%d", re);
	}

	fclose(inp);
	fclose(oup);
}