#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

typedef struct coordinate {
	int x, y;
}coordinate;

bool cmp(const coordinate &p1, const coordinate &p2) {
	if (p1.x < p2.x) {
		return true;
	}
	else if (p1.x == p2.x) {
		return p1.y < p2.y;
	}
	else {
		return false;
	}
}

coordinate c1[20001], c2[20001];

void set2(int n) {
	if (c2[0].x == 0 && c2[0].y == 0) return;
	int tmpx = c2[0].x, tmpy = c2[0].y;
	int chkx = 0, chky = 0; //tmp�� �����0 ������1
	if (tmpx < 0) chkx = 1, tmpx *= -1;
	if (tmpy < 0) chky = 1, tmpy *= -1;

	for (int i = 0; i <= n; i++) {
		if (chkx == 1) { //�����̸�
			c2[i].x += tmpx;
		}
		else {
			c2[i].x -= tmpx;
		}
		if (chky == 1) { //�����̸�
			c2[i].y += tmpy;
		}
		else {
			c2[i].y -= tmpy;
		}
	}
}

void set1(int n) {
	if (c1[0].x == 0 && c1[0].y == 0) return;
	int tmpx = c1[0].x, tmpy = c1[0].y;
	int chkx = 0, chky = 0; //tmp�� �����0 ������1
	if (tmpx < 0) chkx = 1, tmpx *= -1;
	if (tmpy < 0) chky = 1, tmpy *= -1;

	for (int i = 0; i <= n; i++) {
		if (chkx == 1) { //�����̸�
			c1[i].x += tmpx;
		}
		else {
			c1[i].x -= tmpx;
		}
		if (chky == 1) { //�����̸�
			c1[i].y += tmpy;
		}
		else {
			c1[i].y -= tmpy;
		}
	}
}

void rotation90(int n) {
	//90�� ȸ��: x,y�� �ٲ��ְ� �ٲ� y�� *=-1
	for (int i = 0; i <= n; i++) {
		int tmp = c2[i].x;
		c2[i].x = c2[i].y;
		c2[i].y = -tmp;
	}
}
/*
void rotation180(int n) {
	//180�� ȸ��: x, y�� ���� *=-1
	for (int i = 0; i <= n; i++) {
		c2[i].x *= -1;
		c2[i].y *= -1;
	}
}

void rotation270(int n) {
	//270�� ȸ��: x,y �� �ٲ��ְ� �ٲ� x�� *=-1
	for (int i = 0; i <= n; i++) {
		int tmp = c2[i].x;
		c2[i].x = -c2[i].y;
		c2[i].y = tmp;
	}
}
*/

int isSame(int n) {
	for (int j = 0; j < n; j++) {
		if (c1[j].x == c2[j].x && c1[j].y == c2[j].y) continue;
		else {
			return 0;
		}
	}
	return 1;
}

int main() {
	ofstream out("polygon.out");
	ifstream inp("polygon.inp");
	int t;
	inp >> t;
	for (int i = 0; i < t; i++) {
		int n;
		inp >> n;
		int arr1[20001], arr2[20001];
		
		coordinate tmp; //������ǥ
		int location = 0; //0�� ��, 1�� ��, 2�� ��, 3�� ��
		tmp.x = 0, tmp.y = 0; 
		c1[0].x = 0, c2[0].x = 0;
		c1[0].y = 0, c2[0].y = 0;
		arr1[0] = 0, arr2[0] = 0; //�ʿ��������
		for (int j = 1; j <= n; j++) {
			//����Ÿ�Ӷ߸� arr�� [2]�� �������ְ� �ٽ� �غ���
			inp >> arr1[j];
			int temp = arr1[j];
			if (temp < 0) temp *= -1;
			if (j != 1) {
				if (arr1[j-1] > 0) { //L
					if (location == 0) location = 2;
					else if (location == 1) location = 3;
					else if (location == 2) location = 1;
					else location = 0;
				}
				else { //R
					if (location == 0) location = 3;
					else if (location == 1) location = 2;
					else if (location == 2) location = 0;
					else location = 1;
				}
			}

			if (j % 2 != 0) { //y��ǥ ����
				if (location == 0) tmp.y += temp;
				else if (location == 1) tmp.y -= temp;
			}
			else { //x��ǥ ����
				if (location == 2) tmp.x -= temp;
				else if (location == 3) tmp.x += temp;
			}
			if (j == n) break; //������ ��ǥ�� ����
			c1[j].x = tmp.x;
			c1[j].y = tmp.y;
		}
		location = 0; //0�� ��, 1�� ��, 2�� ��, 3�� ��
		tmp.x = 0, tmp.y = 0;
		for (int j = 1; j <= n; j++) {
			inp >> arr2[j];
			int temp = arr2[j];
			if (temp < 0) temp *= -1;
			if (j != 1) {
				if (arr2[j-1] > 0) { //L
					if (location == 0) location = 2;
					else if (location == 1) location = 3;
					else if (location == 2) location = 1;
					else location = 0;
				}
				else { //R
					if (location == 0) location = 3;
					else if (location == 1) location = 2;
					else if (location == 2) location = 0;
					else location = 1;
				}
			}

			if (j % 2 != 0) { //y��ǥ ����
				if (location == 0) tmp.y += temp;
				else if (location == 1) tmp.y -= temp;
			}
			else { //x��ǥ ����
				if (location == 2) tmp.x -= temp;
				else if (location == 3) tmp.x += temp;
			}
			if (j == n) break; //������ ��ǥ�� ����
			c2[j].x = tmp.x;
			c2[j].y = tmp.y;
		}
		sort(c1, c1 + n, cmp);
		sort(c2, c2 + n, cmp);
		set1(n),set2(n);
		int check = 0;
		check = isSame(n);
		
		if (check == 1) {
			out << "1" << endl;
			continue;
		}
		else {
			rotation90(n);
			sort(c2, c2 + n, cmp);
			set1(n),set2(n);
			check = isSame(n);
			if (check == 1) {
				out << "1" << endl;
				continue;
			}
			else {
				rotation90(n);
				sort(c2, c2 + n, cmp);
				set1(n), set2(n);
				check = isSame(n);
				if (check == 1) {
					out << "1" << endl;
					continue;
				}
				else {
					rotation90(n);
					sort(c2, c2 + n, cmp);
					set1(n), set2(n);
					check = isSame(n);
					if (check == 1) {
						out << "1" << endl;
						continue;
					}
					else {
						out << "0" << endl;
						continue;
					}
				}
			}
		}
	}

	inp.close(), out.close();
}