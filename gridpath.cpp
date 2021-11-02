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
	bool operator()(pip a, pip b) {  // 가중치가 동일하면 우측경로를 택한다.
		if (a.first == b.first)
			return a.second.first > b.second.first;
		else
			return a.first > b.first;
	}
};

priority_queue< pair<int, pii>, vector<pair<int, pii>>, compare > pq;
/*
   우선순위 큐에는 누적 가중치가 들어가게 된다
   이미 check에 MAX가 아닌 가중치의 값이 들어가 있다면
   새로운 경로의 가중치 값과 비교하여 더 작은 값이면 갱신시켜 준다.
*/
stack<pii> point;

int n, m;
bool flag = false;
int field[201][201]; // 가중치 저장
int check[201][201]; // 누적 가중치 저장
pii v[201][201];    // 지나온 경로체크

void init_field() { // 초기화 및 입력

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			inp >> field[i][k]; // 가중치를 받는다
			check[i][k] = MAX; // 초기화
		}
	}
}

void find_node() { // 경로 출력을 위한 함수

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
	pq.push(pip(check[0][0], pii(0, 0))); // 출발 위치 삽입


	while (!pq.empty()) {
		int curx = pq.top().second.first; // 현재 위치
		int cury = pq.top().second.second;
		int curw = pq.top().first; // 현재 가중치
		pq.pop();

		if (curx == n - 1 && cury == m - 1) break;

		if (curx == n - 1) { // 마지막 행이면 오른쪽만 확인
			int rx = curx;  // 오른쪽 좌표
			int ry = cury + 1;
			int rw = curw + field[rx][ry]; // 오른쪽 가중치

			if (field[rx][ry] == -1) // -1을 만나면
				continue;

			if (check[rx][ry] > rw) {
				v[rx][ry] = pii(curx, cury);
				check[rx][ry] = rw;
				pq.push(pip(rw, pii(rx, ry)));
			}

		}

		else if (cury == m - 1) { // 마지막 열이면 아래쪽만 확인
			int dx = curx + 1;  // 아래쪽 좌표
			int dy = cury;
			int dw = curw + field[dx][dy]; // 아래쪽 가중치

			if (field[dx][dy] == -1) // -1을 만나면
				continue;

			if (check[dx][dy] > dw) {
				v[dx][dy] = pii(curx, cury);
				check[dx][dy] = dw;
				pq.push(pip(dw, pii(dx, dy)));
			}

		}

		else { // 그 외 좌표
			int rx = curx;
			int ry = cury + 1;
			int rw = curw + field[rx][ry];

			int dx = curx + 1;
			int dy = cury;
			int dw = curw + field[dx][dy];

			if (field[rx][ry] == -1 && field[dx][dy] == -1) { // 막다른 길
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
	init_field(); // 가중치 초기화
	find_Dist(); // 최소경로 탐색
	if (!flag)
		out << "No path.";
	else
		find_node(); // 경로가 있다면 출력

	inp.close();
	out.close();
}