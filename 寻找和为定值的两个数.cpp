#define   _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;
void Sum_two(int *a, int n,int sum)
{
	sort(a, a + n);
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		int currSum = a[begin] + a[end];
		if (currSum == sum)
		{
			printf("%d %d\n", a[begin], a[end]);
			break;
		}
		else if (currSum < sum)
			begin++;
		else
			end--;

	}
}



int main()
{
	int a[8] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Sum_two(a, 8,13);
	
	system("pause");
	return  0;

}