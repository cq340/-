#include <iostream>
using namespace std;
int x[5] = { 1, 2, 3, 4, 5 };
int n = 5;
int m;


void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
bool BackTrack(int t) {
	if (t == n) {
		int sum = 0;
		int flag = 1;
		for (int i = 0; i < n; i++) {
			sum += x[i] * flag;
			flag = -flag;
		}
		if (sum == m) return true;
	}
	else
	for (int i = t; i < n; i++) {
		swap(x[t], x[i]);
		if (BackTrack(t + 1))
			return true;
		//swap(x[t], x[i]);
	}
	return false;
}
int main() {
	m = 1;
	if (BackTrack(0)) {
		cout << "找到排列满足条件: ";
		for (int i = 0; i < n; i++) {
			cout << x[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "不存在这样的排列" << endl;
	}
	system("pause");
	return 0;
}
