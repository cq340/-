#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <cmath>  
#include <time.h> 
using namespace std;
static int n, x[1000], y[1000];
static    long sum;
int Place(int k)
{
	for (int j = 1; j <k; j++)
	if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k])) return 0;
	return 1;
}


void Backtrak(int t)
{
	if (t>n)
	{
		sum++;
		for (int i = 1; i <= n; i++)
		{
			printf("%d  ", x[i]);
		}
		printf("\n");
	}
	else
	for (int i = 1; i <= n; i++)
	{
		x[t] = i;
		if (Place(t))Backtrak(t + 1);
	}
}



int main()
{
	int nn, stopVEgas;
	//srand((unsigned)time(NULL));
	printf("请输入皇后的数量和随机数的数量\n");
	while (scanf("%d%d", &nn, &stopVEgas) != EOF) //输入皇后的数量
	{
		n = nn;
		sum = 0;
		while (true)
		{
			for (int i = 0; i <= n; i++)
				x[i] = 0;
			for (int j = 1; j <= stopVEgas; j++)
			{
				x[j] = rand() % n + 1;
				if (!Place(j))
				{
					j--;
				}
			}
			Backtrak(stopVEgas + 1);
			if (sum!=0)
				break;
		}
	}
}
