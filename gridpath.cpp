#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include<fstream>
#define MAX 90000000
using namespace std;

ifstream inp("gridpath.inp");
ofstream out("gridpath.out");
typedef pair<int, int>  pii;
typedef pair<int, pii>  pip;

struct compare {
	bool operator()(pip a, pip b) {  // ����ġ�� �����ϸ� ������θ� ���Ѵ�.
		if (a.first == b.first)
			return a.second.first > b.second.first;
		else
			return a.first > b.first;
	}
};

priority_queue< pair<int, pii>, vector<pair<int, pii>>, compare > pq;
/*
   �켱���� ť���� ���� ����ġ�� ���� �ȴ�
   �̹� check�� MAX�� �ƴ� ����ġ�� ���� �� �ִٸ�
   ���ο� ����� ����ġ ���� ���Ͽ� �� ���� ���̸� ���Ž��� �ش�.
*/
stack<pii> point;

int n, m;
bool flag = false;
int field[201][201]; // ����ġ ����
int check[201][201]; // ���� ����ġ ����
pii v[201][201];    // ������ ���üũ

void init_field() { // �ʱ�ȭ �� �Է�

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			inp >> field[i][k]; // ����ġ�� �޴´�
			check[i][k] = MAX; // �ʱ�ȭ
		}
	}
}

void find_node() { // ��� ����� ���� �Լ�

	int x = n - 1;
	int y = m - 1;
	out << check[x][y] << "\n";
	point.push(pii(x, y));

	while (true) {

		int prex = v[x][y].first;
		int prey = v[x][y].second;

		point.push(pii(prex, prey));
		x = prex;
		y = prey;

		if (prex == 0 && prey == 0)
			break;
	}

	while (!point.empty()) {
		out << "(" << point.top().first << " " << point.top().second << ")" << "\n";
		point.pop();
	}
}

void find_Dist() {

	check[0][0] = field[0][0];
	pq.push(pip(check[0][0], pii(0, 0))); // ��� ��ġ ����


	while (!pq.empty()) {
		int curx = pq.top().second.first; // ���� ��ġ
		int cury = pq.top().second.second;
		int curw = pq.top().first; // ���� ����ġ
		pq.pop();

		if (curx == n - 1 && cury == m - 1) break;

		if (curx == n - 1) { // ������ ���̸� �����ʸ� Ȯ��
			int rx = curx;  // ������ ��ǥ
			int ry = cury + 1;
			int rw = curw + field[rx][ry]; // ������ ����ġ

			if (field[rx][ry] == -1) // -1�� ������
				continue;

			if (check[rx][ry] > rw) {
				v[rx][ry] = pii(curx, cury);
				check[rx][ry] = rw;
				pq.push(pip(rw, pii(rx, ry)));
			}

		}

		else if (cury == m - 1) { // ������ ���̸� �Ʒ��ʸ� Ȯ��
			int dx = curx + 1;  // �Ʒ��� ��ǥ
			int dy = cury;
			int dw = curw + field[dx][dy]; // �Ʒ��� ����ġ

			if (field[dx][dy] == -1) // -1�� ������
				continue;

			if (check[dx][dy] > dw) {
				v[dx][dy] = pii(curx, cury);
				check[dx][dy] = dw;
				pq.push(pip(dw, pii(dx, dy)));
			}

		}

		else { // �� �� ��ǥ
			int rx = curx;
			int ry = cury + 1;
			int rw = curw + field[rx][ry];

			int dx = curx + 1;
			int dy = cury;
			int dw = curw + field[dx][dy];

			if (field[rx][ry] == -1 && field[dx][dy] == -1) { // ���ٸ� ��
				continue;
			}

			if (field[rx][ry] != -1) {
				if (check[rx][ry] > rw) {
					v[rx][ry] = pii(curx, cury);
					check[rx][ry] = rw;
					pq.push(pip(rw, pii(rx, ry)));
				}
			}

			if (field[dx][dy] != -1) {
				if (check[dx][dy] > dw) {
					v[dx][dy] = pii(curx, cury);
					check[dx][dy] = dw;
					pq.push(pip(dw, pii(dx, dy)));
				}
			}
		}
	}

	if (check[n - 1][m - 1] == MAX)
		flag = false;
	else
		flag = true;


}

int main(void) {
	inp >> n >> m;
	init_field(); // ����ġ �ʱ�ȭ
	find_Dist(); // �ּҰ�� Ž��
	if (!flag)
		out << "No path.";
	else
		find_node(); // ��ΰ� �ִٸ� ���

	inp.close();
	out.close();
}