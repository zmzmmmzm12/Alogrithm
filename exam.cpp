#include<stdio.h>
#include<string.h>

void print(FILE * oup, int b) {

}

int main() {
	FILE * inp = fopen("exam.inp", "r");
	FILE * oup = fopen("exam.out", "w");
	int i, j, l, m; //�ݺ�����������
	int cnt, cntP, cntnQ, cntQ;
	int k, index_p, index_Q;
	int T; //�� �׽�Ʈ���̽��� ��
	char arr[26]; //���� ������ ������ ���� arr
	char p[1000]; //���ڿ� ����
	int n; //���Ǿ��� ��
	char Q[1000]; //���Ǿ� ���ڿ�


	fscanf(inp, "%d", &T);

	for (i = 0; i < T; i++) {
		fscanf(inp, "%s", &arr); //������������
		fscanf(inp, "%s", &p);//����
		fscanf(inp, "%d", &n);//���Ǿ� ��
		fprintf(oup, "Test Case: #%d\n", i);
		for (j = 0; j < n; j++) {
			cnt = 0; cntP = 0; cntnQ = 0, cntQ = 0;
			fscanf(inp, "%s", &Q); //���Ǿ�ڿ�
			//���� �������� ¥��
			//l���� �־ ¥�� ����������?
			//��� ©�� �ٽ� ����.
			//for���� �ٲٴ��� !!
		//	for (k = 0; k < strlen(p); k++) {
				for (l = 0; l < strlen(Q); l++) {
					if (p[l] != Q[l]) { //���� �� ���ڰ� �ٸ���
						cnt++; //�������� cnt==cntP+cntQ���� ����
						if (p[l] == '?') { //?�϶�
							for (m = 0; m < strlen(arr); m++) {
								if (Q[l] == arr[m]) { //������������ Ȯ��
									cntP++; break; //������ �극��ũ
								}
							}
						}
						else if (p[l] == '*') { //*�϶�
							//*�ڿ������� *���� �б�
							k = l; //*�� index
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