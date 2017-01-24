#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	unsigned long long f[10002];
	long n;
	int p[4] = { 1, 2, 5, 10 };
	while (scanf("%ld", &n) == 1)
	{
		for (int i = 3; i >= 0;i--)
		for (int j = p[i]; j <= n; j++)
		{
			f[j] = f[j] + f[j - p[i]];
		}
		cout << f[n] << endl;
		system("pause");
		return 0;
	}
}