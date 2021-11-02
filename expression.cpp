#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

int main() {
	ofstream out("expression.out");
	ifstream inp("expression.inp");
	int t;
	inp >> t;
	for (int i = 0; i < t; i++) {
		stack<int>number;
		stack<char>oper;
		int n, check = 0; //check==1이면 Error!
		inp >> n;
		number.push(n);
		char op;
		inp >> op;
		while (op != '=') {
			if (op == '*') {
				inp >> n;
				number.top() *= n;
			}
			else if (op == '/' || op == '%') {
				inp >> n;
				if (n == 0) {
					check = 1;
					n = 10; //그냥 계산하라고 넣어준 의미없는 숫자
					//check==1이면 Error!을 출력하게 할것임
				}
				if (op == '/') number.top() /= n;
				else number.top() %= n;
			}
			else if (op == '+' || op == '-') {
				inp >> n;
				if (!oper.empty()) {
					int tmp = number.top();
					number.pop();
					if (oper.top() == '+') number.top() += tmp;
					else number.top() -= tmp;
					oper.pop();
					oper.push(op);
					number.push(n);
				}
				else {
					oper.push(op);
					number.push(n);
				}
			}
			inp >> op;
		}
		while (check == 0 && !oper.empty()) {
			int tmp = number.top();
			number.pop();
			if (oper.top() == '+') number.top() += tmp;
			else number.top() -= tmp;
			oper.pop();
		}
		if (check == 1) {
			out << "Error!" << endl;
		}
		else {
			out << number.top() << endl;
		}
	}

	inp.close();
	out.close();
}