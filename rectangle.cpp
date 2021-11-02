#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct coor {
	long long int x, y, dist;
	int resA, resB;
};

coor arr[1010101];
coor idxArr[3010101];

bool cmp(coor a, coor b) {
	if (a.dist != b.dist) return a.dist < b.dist;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int main() {
	ifstream inp("rectangle.inp");
	ofstream out("rectangle.out");
	int t;
	inp >> t;
	while (t--) {
		long long int n;
		inp >> n;
		for (long long int i = 1; i <= n; i++)
			inp >> arr[i].x >> arr[i].y;
		long long int cnt = 0;
		for (long long int i = 1; i <= n; i++)
			for (long long int j = i + 1; j <= n; j++) {
				cnt++;
				idxArr[cnt] = {
				   (arr[i].x - arr[j].x)*(arr[i].x - arr[j].x) + (arr[i].y - arr[j].y)*(arr[i].y - arr[j].y),
				   arr[i].x + arr[j].x,
				   arr[i].y + arr[j].y,
				   (int)i,
				   (int)j
				};
			}
		sort(idxArr + 1, idxArr + 1 + cnt, cmp);
		long long int res = 0;
		for (long long int i = 1; i < cnt; i++) {
			long long int l = i + 1;
			while (idxArr[i].x == idxArr[l].x&&idxArr[i].y == idxArr[l].y&&idxArr[i].dist == idxArr[l].dist) {
				res = max(res,
					abs(arr[idxArr[i].resA].x*(arr[idxArr[i].resB].y - arr[idxArr[l].resA].y)
						+ arr[idxArr[i].resB].x*(arr[idxArr[l].resA].y - arr[idxArr[i].resA].y)
						+ arr[idxArr[l].resA].x*(arr[idxArr[i].resA].y - arr[idxArr[i].resB].y))
					+ abs(arr[idxArr[i].resA].x*(arr[idxArr[i].resB].y - arr[idxArr[l].resB].y)
						+ arr[idxArr[i].resB].x*(arr[idxArr[l].resB].y - arr[idxArr[i].resA].y)
						+ arr[idxArr[l].resB].x*(arr[idxArr[i].resA].y - arr[idxArr[i].resB].y)));
				l++;
			}
		}
		out << res / 2 << endl;
	}
	inp.close(), out.close();
}