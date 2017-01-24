#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearch(int *a, int n, int value)
{
	sort(a, a + n);
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int middle = left + ((right - left) >> 1);
		if (a[middle] > value)
			right = middle - 1;
		else if (a[middle] < value)
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}


int main()
{
	int a[8] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int k = BinarySearch(a, 8, 10);
	if (k == -1)
		cout << "不存在";
	else
		cout << "成功找到";
	system("pause");
	return 0;
}