#include<stdio.h>

struct bowlingScore {
	int one, two, three = -1;
};

int main() {
	FILE * inp = fopen("bowling.inp", "r");
	FILE * out = fopen("bowling.out", "w");
	int T, result;
	bowlingScore f[10];

	fscanf(inp, "%d", &T);

	for (int i = 0; i < T; i++) {
		result = 0;

		for (int i = 0; i < 10; i++) {
			f[i].one = 0, f[i].two = 0, f[i].three = -1;
		}

		for (int j = 0; j < 9; j++) {
			fscanf(inp, "%d", &f[j].one);
			if (f[j].one == 10) continue;
			fscanf(inp, "%d", &f[j].two);
		}

		fscanf(inp, "%d %d", &f[9].one, &f[9].two);

		if (f[9].one == 10 || f[9].one + f[9].two == 10) {
			fscanf(inp, "%d", &f[9].three);
		}

		for (int j = 0; j < 9; j++) {
			if (f[j].one == 10) {
				if (f[j + 1].one == 10) {
					result += 10;
					if (j == 8) result += f[j + 1].two;
					else result += f[j + 2].one;
				}
				else result += (f[j + 1].one + f[j + 1].two);
			}
			else if (f[j].one + f[j].two == 10) {
				result += f[j + 1].one;
			}
			result += (f[j].one + f[j].two);
		}

		result += (f[9].one + f[9].two);

		if (f[9].three > 0) {
			result += f[9].three;
		}

		fprintf(out, "%d\n", result);
	}
	fclose(inp), fclose(out);
}