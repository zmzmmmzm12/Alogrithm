#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string datearr[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
int year1, year2, month1, month2, day1, day2, num1, num2, check=1;
char k;
string date1, date2;

int yun(int year) {
	int ok;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ok = 1;
	else ok = 0;
	if (ok==1) return 1;
	else return 0;
}

int YMD(int year, int month, int day) {
	int montharr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (yun(year)) montharr[1] = 29;
	if (montharr[month - 1] < day) { check = 0; return -1; }
	int days = 0;
	for (int i = 1; i < year; i++) {
		if (yun(i)==1) days += 366;
		else days += 365;
	}
	for (int i = 0; i <= month - 1; i++) {
		for (int j = 1; j <= montharr[i]; j++) {
			if (month - 1 == i && j == day) {
				check = 1; return days;
			}
			days++;
		}
	}
}

int YMND(int year, int month, int num, string date) {
	int montharr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (yun(year)==1) montharr[1] = 29;
	int days = 0;
	int week = 1;
	for (int i = 1; i < year; i++) {
		if (yun(i)) days += 366, week += 2;
		else days += 365, week += 1;
		week %= 7;
	}
	if (week == 0) week = 6;
	else week--;
	for (int i = 0; i < month ; i++) {
		int roof = 0; int n = 1;
		for (int j = 1; j <= montharr[i]; j++) {
			roof++, days++, week++;
			if (week > 6) week = 0;
			if (roof == 8) roof = 1, n++;
			if ((month - 1) == i && n == num && date.compare(datearr[week]) == 0) {
				check = 1;
				return (days-1);
			}
		}
	}
	check = 0;
	return -1;
}

int main() {
	freopen("calendar.inp", "r", stdin);
	freopen("calendar.out", "w", stdout);
	int type = 0;
	while (type != -1) {
		cin >> type;
		int re1, re2;
		int re;
		if (type == 0) {
			cin >> year1 >> k >> month1 >> k >> day1 >> year2 >> k >> month2 >> k >> day2;
			re1 = YMD(year1, month1, day1);
			if (check == 0) {
				cout << "-1" << endl; continue;
			}
			re2= YMD(year2, month2, day2);
			re = re1 - re2;
			if (check == 0) {
				cout << "-1" << endl; continue;
			}
			if (re < 0)re *= -1;
			cout << re << endl;
		}
		else if (type == 1) {
			cin >> year1 >> k >> month1 >> k >> day1 >> year2 >> k >> month2 >> k >> num2 >> k >> date2;
			re1 = YMD(year1, month1, day1);
			if (check == 0) {
				cout << "-1" << endl; continue;
			}
			re2= YMND(year2, month2, num2, date2);
			re = re1 - re2;
			if (check == 0) {
				cout << "-1" << endl; continue;
			}
			if (re < 0)re *= -1;
			cout << re << endl;
		}
		else if (type == 2) {
			cin >> year1 >> k >> month1 >> k >> num1 >> k >> date1 >> year2 >> k >> month2 >> k >> day2;
			re1 = YMND(year1, month1, num1, date1);
			if (check == 0) {
				cout << "-1" << endl; continue;
			}
			re2 = YMD(year2, month2, day2);
			re = re1 - re2;
			if (check == 0) {
				cout << "-1" << endl; continue;
			}
			if (re < 0)re *= -1;
			cout << re << endl;
		}
		else if (type == 3) {
			cin >> year1 >> k >> month1 >> k >> num1 >> k >> date1>>year2 >> k >> month2 >> k >> num2 >> k >> date2;
			re1 = YMND(year1, month1, num1, date1);
			if (check == 0) {
				cout << "-1" << endl; continue;
			}
			re2= YMND(year2, month2, num2, date2);
			re = re1 - re2;
			if (check == 0) {
				cout << "-1" << endl; continue;
			}
			if (re < 0)re *= -1;
			cout << re << endl;
		}
		else break;
	}
}