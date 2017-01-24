#include "iostream"
#include "algorithm"
#include "fstream"
using namespace std;

/*
h(n)为n的划分数
h(1) = 1
h(2) = 1
h(n) = h(n/2) + h(n/3) + ... + h(n/n)  前提是能被整除
*/

int h[100];

//动态规划
int solve(int n)
{
	h[1] = 1;
	h[2] = 1;
	for (int i = 3; i <= n; i++)
	for (int j = 2; j <= i; j++)
	if (i%j == 0) //如果j能被i整除
		h[i] += h[i / j];
	return  h[n];
}

//递归
int total = 0;
int recursive(int n)
{
	if (n == 1 || n == 2)
		return 1;
	for (int i = 3; i <= n; i++)
	if (n%i == 0)
		total += recursive(n / i);
	return total;
}

int main()
{
	int n;
	cout << "输入正整数数：";
	cin >> n;
	int count = solve(n);
	//cout << "分解式的种数为（动态规划）：";
	cout << count << endl;
	cout << "分解式的种数为（递归）：";
    count = recursive(n);
	cout << count << endl;
	system("pause");
	return 0;
}