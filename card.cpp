#include <iostream>
#include <fstream>
#include <algorithm>
#define trash -100000002;
using namespace std;

int main() {
	ifstream inp("card.inp");
	ofstream out("card.out");
	int t, numSize, cnt = 0;
	int num[1005];
	int arr[1005][3];
	inp >> t;
	while(cnt<t){
		inp >> numSize;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < numSize + 5; j++) {
				arr[j][i] = trash;
			}
		}
		for (int i = 0; i < numSize; i++) {
			inp >> num[i];
		}
		int result = trash;
		for (int i = 0; i < 3; i++) arr[numSize - 1][i] = num[numSize - 1];
		for (int i = numSize - 2; i >= 0; i--) {
			arr[i][0] = max(arr[i + 2][1], arr[i + 2][2]) + num[i];
			arr[i][1] = max(arr[i + 3][0], max(arr[i + 3][1], arr[i + 3][2])) + num[i];
			arr[i][2] = max(arr[i + 4][0], max(arr[i + 4][1], arr[i + 4][2])) + num[i];
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i + j == 0) continue;
				result = max(result, arr[i][j]);
			}
		}
		out << result << endl;
		cnt++;
	}
	inp.close();
	out.close();
}