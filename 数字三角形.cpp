#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int n, d[101][101];
	cin >> n;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= i; j++)
		cin >> d[i][j];
	for (int i = n - 1; i >= 1; i--)
	for (int j = 1; j <= i; j++)
		d[n][j] = max(d[n][j], d[n][j + 1]) + d[i][j];
	cout <<"½á¹ûÎª"<< d[n][1] << endl;
	system("pause");
}