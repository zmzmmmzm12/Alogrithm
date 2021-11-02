#include<stdio.h>

void bubbleSort(int a[], int b[], int c[], int N) {
	//���� �ð� ����
	for (int i = 0; i < N; i++) {
		int j;
		for (j = 0; j < N  - 1; j++) {
			if (a[j] > a[j + 1]) {
				int min = a[j + 1];
				a[j + 1] = a[j];
				a[j] = min;
				min = b[j + 1];
				b[j + 1] = b[j];
				b[j] = min;
				min = c[j + 1];
				c[j + 1] = c[j];
				c[j] = min;
			}
			if (a[j] == a[j + 1]) { //�����ð�����
				if (c[j] > c[j + 1]) { //���μ��� ��ȣ �����ź��� ����
					int min = a[j + 1];
					a[j + 1] = a[j];
					a[j] = min;
					min = b[j + 1];
					b[j + 1] = b[j];
					b[j] = min;
					min = c[j + 1];
					c[j + 1] = c[j];
					c[j] = min;
				}
			}
		}
	}
}

void sort(int a[], int b[], int c[], int d, int f) {
	//�켱���� �������� �����Ұ�
	//���� �ð� ����
	for (int i = d; i < f; i++) {
		for (int j = d; j < f - 1; j++) {
			if (b[j] > b[j + 1]) {
				int min = a[j + 1];
				a[j + 1] = a[j];
				a[j] = min;
				min = b[j + 1];
				b[j + 1] = b[j];
				b[j] = min;
				min = c[j + 1];
				c[j + 1] = c[j];
				c[j] = min;
			}
			if (b[j] == b[j + 1]) { //�����ð�����
				if (c[j] > c[j + 1]) { //���μ��� ��ȣ �����ź��� ����
					int min = a[j + 1];
					a[j + 1] = a[j];
					a[j] = min;
					min = b[j + 1];
					b[j + 1] = b[j];
					b[j] = min;
					min = c[j + 1];
					c[j + 1] = c[j];
					c[j] = min;
				}
			}
		}
	}
}

int main() {
	FILE * inp = fopen("sjf.inp", "r");
	FILE * out = fopen("sjf.out", "w");
	int n, wating = 0,tmp, tmp1,tmp2, i, j, k = 0, l;
	int number[50], arrive[50], use[50];
	fscanf(inp, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d %d %d", &number[i], &arrive[i], &use[i]);
	}
	//����������
	//÷�� bubble�� �������ְ�, ���ϴ� �������� sort������ϴµ�,,
	bubbleSort(arrive, use, number, n);
	
	for (int i = 1; i < n; i++) {
		tmp = arrive[k];
		for (j = k; j < i; j++) {
			tmp += use[j];
		}
		if ((arrive[i] - tmp) > 0) {
			tmp += (arrive[i] - tmp);
			k = i;
		}
		for (l = i; l < n; l++) {
			if (arrive[l] > tmp) {
				break;
			}
		}
		sort(arrive, use, number, i, l);
	}
	k = 0;
	for (i = 1; i < n; i++) {
		tmp1 = 0;
		for (j = k; j < i; j++) {
			tmp1 += use[j];
		}
		tmp2 = tmp1 - arrive[i]+arrive[k];
		if (tmp2 <= 0) {
			k = i;
		}
		else {
			wating += tmp2;
		}
	}

	fprintf(out, "%d", wating);
	fclose(inp), fclose(out);
}