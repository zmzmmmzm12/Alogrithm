//�ƿ����� �̽� �߸� �� cpp���� �̸� jollo.cpp�� �ٲܰ�
#include<stdio.h>

int main() {
	FILE * inp = fopen("jollo.inp", "r");
	FILE * out = fopen("jollo.out", "w");
	int a=1, b=1, c=1, x=1, y=1;
	int max_w, mid_w, min_w, max_m, mid_m, re;
	while (1) {
		fscanf(inp,"%d %d %d %d %d", &a, &b, &c, &x, &y);
		if (a == 0) break;
		if (a < b) {
			if (b < c)max_w = c, mid_w = b, min_w = a;
			else {
				if(a<c)max_w = b, mid_w = c, min_w = a;
				else max_w = b, mid_w = a, min_w = c;
			}
		}
		else {
			if (a < c)max_w =c, mid_w =a, min_w = b;
			else {
				if (b < c)max_w =a, mid_w = c, min_w = b;
				else max_w = a, mid_w = b, min_w = c;
			}
		}
		if (x < y) max_m = y, mid_m=x;
		else max_m = x, mid_m = y;

		//���ְ� �̱�� ���ڴ� ���� �����ҵ� ���ֺ��ٳ�����
		//�׸��� ���ְ� ���� ������ ���� ���ڴ� �״���������
		//���� ���ڰ� ���� �������϶��� ���ְ� ���ϳ�����
		//�׸��� ���ڰ� �״��������Ŵ� ���ų�,..��ư����
		if (max_m > max_w) {
			if (max_w > mid_m) {
				if (mid_m > mid_w) {
					re = mid_w + 1;
				}
				else {
					re = max_w + 1;
				}
			}
			else {
				re = 1;
				if (min_w == re)re += 1;
				if (mid_w == re)re += 1;
				if (mid_m == re)re += 1;
				if (max_w == re)re += 1;
				if (max_m == re)re += 1;
			}
		}
		else {
			if (mid_m > min_w) re = mid_w + 1;
			else re = -1;
			if (mid_m < mid_w)re = -1;
		}
		if (min_w == re)re += 1;
		if (mid_w == re)re += 1;
		if (mid_m == re)re += 1;
		if (max_w == re)re += 1;
		if (max_m == re)re += 1;
		if (re > 52)re = -1;
		fprintf(out, "%d\n", re);

	}//������ 1~52�ϱ� �ϳ��� 0�̸� ����

	fclose(inp); fclose(out);
}