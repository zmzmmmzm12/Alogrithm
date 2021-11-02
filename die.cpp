#include<stdio.h>
#include<iostream>
using namespace std;

int x, y, top, front, index_right, index_left, index_top, index_bottom, index_front, index_back;
int die[6];
char move_direction[1001];

void set() {
	if (index_right == 0) index_left = 2;
	else if (index_right == 1) index_left = 4;
	else if (index_right == 2) index_left = 0;
	else if (index_right == 3) index_left = 5;
	else if (index_right == 4) index_left = 1;
	else if (index_right == 5) index_left = 3;

	if (index_top == 0) index_bottom = 2;
	else if (index_top == 1) index_bottom = 4;
	else if (index_top == 2) index_bottom = 0;
	else if (index_top == 3) index_bottom = 5;
	else if (index_top == 4) index_bottom = 1;
	else if (index_top == 5) index_bottom = 3;

	if (index_front == 0) index_back = 2;
	else if (index_front == 1) index_back = 4;
	else if (index_front == 2) index_back = 0;
	else if (index_front == 3) index_back = 5;
	else if (index_front == 4) index_back = 1;
	else if (index_front == 5) index_back = 3;

	return;
}

void swap(int *a, int *b, int *c, int *d) {
	int temp = *a;
	*a = *d, *d = *c, *c = *b, *b = temp;
	return;
}

void check() {
	for (int i = 0; i < 6; i++) {
		if (top == die[i]) index_top = i;
		if (front == die[i]) index_front = i;
	}
	if (index_top == 0) {
		if (index_front == 1) { index_right = 3; return; }
		else if (index_front == 3) { index_right = 4; return; }
		else if (index_front == 4) { index_right = 5; return; }
		else if (index_front == 5) { index_right = 1; return; }
	}
	else if (index_top == 1) {
		if (index_front == 0) { index_right = 5; return; }
		else if (index_front == 2) { index_right = 3; return; }
		else if (index_front == 3) { index_right = 0; return; }
		else if (index_front == 5) { index_right = 2; return; }
	}
	else if (index_top == 2) {
		if (index_front == 1) { index_right = 5; return; }
		else if (index_front == 3) { index_right = 1; return; }
		else if (index_front == 4) { index_right = 3; return; }
		else if (index_front == 5) { index_right = 4; return; }
	}
	else if (index_top == 3) {
		if (index_front == 0) { index_right = 1; return; }
		else if (index_front == 1) { index_right = 2; return; }
		else if (index_front == 2) { index_right = 4; return; }
		else if (index_front == 4) { index_right = 0; return; }
	}
	else if (index_top == 4) {
		if (index_front == 0) { index_right = 3; return; }
		else if (index_front == 2) { index_right = 5; return; }
		else if (index_front == 3) { index_right = 2; return; }
		else if (index_front == 5) { index_right = 0; return; }
	}
	else if (index_top == 5) {
		if (index_front == 0) { index_right = 4; return; }
		else if (index_front == 1) { index_right = 0; return; }
		else if (index_front == 2) { index_right = 1; return; }
		else if (index_front == 4) { index_right = 2; return; }
	}
}

void s() {
	y--;
	swap(&index_front, &index_bottom, &index_back, &index_top);
}

void n() {
	y++;
	swap(&index_front, &index_top, &index_back, &index_bottom);
}

void e() {
	x++;
	swap(&index_right, &index_bottom, &index_left, &index_top);
}

void w() {
	x--;
	swap(&index_right, &index_top, &index_left, &index_bottom);
}

void move(char direction) {
	set();
	if (direction == 'E') e();
	else if (direction == 'W') w();
	else if (direction == 'S') s();
	else if (direction == 'N') n();
}

int main() {
	FILE * inp = fopen("die.inp", "r");
	FILE * out = fopen("die.out", "w");
	int T, cT, i, j;
	fscanf(inp, "%d", &T);
	for (i = 0; i < T; i++) {
		x = 0, y = 0;
		for (j = 0; j < 6; j++) {
			fscanf(inp, "%d", &die[j]);
		}
		fscanf(inp, "%d %d", &top, &front);
		fscanf(inp, "%d", &cT);
		check();
		fscanf(inp, "%c", &move_direction[0]);
		for (j = 0; j < cT; j++) {
			fscanf(inp, "%c", &move_direction[j]);
			move(move_direction[j]);
		}
		fprintf(out, "%d %d %d %d\n", x, y, die[index_top], die[index_front]);
	}
	fclose(inp); fclose(out);
}