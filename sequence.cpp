#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
	FILE * inp = fopen("sequence.inp", "r");
	FILE * out = fopen("sequence.out", "w");
	vector<int> sequence, t;
	int n, tmp;
	fscanf(inp, "%d", &n);
	int *result = new int[n];
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d", &tmp);
		sequence.push_back(tmp);
	}
	sort(sequence.begin(), sequence.end());
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%d", &tmp);
		t.push_back(tmp);
	}

	for (int i = n - 1; i >= 0; i--) {
		vector<int>::iterator it = sequence.begin();
		int re = t[i];
		result[i] = sequence[re];
		sequence.erase(it + re);

	}
	for (int i = 0; i < n; i++) {
		fprintf(out, "%d\n", result[i]);
	}
	fclose(inp), fclose(out);
	return 0;
}