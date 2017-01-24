#include <iostream>
#include<algorithm>
using namespace std;
int x[5] = { 1, 2, 4, 5 }; 
int n = 5;


void BackTrack(int t) {
	if (t == n) {
		for (int i = 0; i < n; i++)
			cout << x[i] << " ";
		cout << endl;

	}
	else
	for (int i = t; i < n; i++) {
		swap(x[t], x[i]);
		BackTrack(t + 1);
		swap(x[t], x[i]);

	}

}
int main() {
	BackTrack(0);
	system("pause");
	return 0;

}
