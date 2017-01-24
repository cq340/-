#define   _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;
int MaxSubArray(int *a, int n)
{
	int  currentSum = 0;
	int maxSum = a[0]; //数组全负的时候返回最大数；

	for (int j = 0; j < n; j++)
	{
		if (currentSum < 0)
		{
			currentSum = a[j];
		}
		else
			currentSum += a[j];
		if (currentSum>maxSum)
			maxSum = currentSum;
	}
	return maxSum;
}



int main()
{
	int a[8] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int max=MaxSubArray(a, 8);
	cout << max<<endl;
	system("pause");
	return  0;

}