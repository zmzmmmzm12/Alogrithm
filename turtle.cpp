#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
	ofstream out("turtle.out");
	ifstream inp("turtle.inp");
	int t;
	inp >> t;
	for (int i = 0; i < t; i++) {
		string a;
		int checkUp = 0, checkDown = 0, checkLeft = 0, checkRight = 0;
		int maxUp = 0, maxDown = 0, maxLeft = 0, maxRight = 0;
		int location = 0; //0,1,2,3������� ��,��,��,��
		inp >> a;
		for (int j = 0; j < a.length(); j++) {
			string tmp = a.substr(j, 1);
			if (tmp.compare("L") == 0) { //�������� 90�� ȸ��
				if (location == 0) location = 2;
				else if (location == 1) location = 3;
				else if (location == 2) location = 1;
				else location = 0;

			}
			else if (tmp.compare("R") == 0) { //���������� 90�� ȸ��
				if (location == 0) location = 3;
				else if (location == 1) location = 2;
				else if (location == 2) location = 0;
				else location = 1;
			}
			else if (tmp.compare("F") == 0) {//������
				if (location == 0) {
					checkUp++; checkDown--;
					if (maxUp < checkUp) maxUp = checkUp;
				}
				else if (location == 1) {
					checkDown++; checkUp--;
					if (maxDown < checkDown) maxDown = checkDown;
				}
				else if (location == 2) {
					checkLeft++; checkRight--;
					if (maxLeft < checkLeft) maxLeft = checkLeft;
				}
				else {
					checkRight++; checkLeft--;
					if (maxRight < checkRight) maxRight = checkRight;
				}
			}
			else { //�ڷ�
				if (location == 0) {
					checkUp--; checkDown++;
					if (maxDown < checkDown) maxDown = checkDown;
				}
				else if (location == 1) {
					checkDown--; checkUp++;
					if (maxUp < checkUp) maxUp = checkUp;
					
				}
				else if (location == 2) {
					checkLeft--; checkRight++;
					if (maxRight < checkRight) maxRight = checkRight;
				}
				else {
					checkRight--; checkLeft++;
					if (maxLeft < checkLeft) maxLeft = checkLeft;
				}
			}
		}
		//���� 500, �¿� 500�迭�� ����
		//check�� �Ǹ� true���ٱ�,..?

		int updown = maxDown+maxUp, leftright = maxLeft+maxRight;

		int re = updown * leftright;
		out << re << endl;
	}

	inp.close();
	out.close();
}