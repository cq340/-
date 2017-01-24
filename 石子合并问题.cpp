#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF = 1000000000;
#define M 110
int dp1[M][M], dp2[M][M];
int sum[M][M];
int num[M];
int min(int a, int b)
{
	return a<b ? a : b;
}
int max(int a, int b)
{
	return a>b ? a : b;
}
int main()
{
	int  n, i, j, k;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		for (i = 1; i <= n; i++)
			sum[i][1] = num[i];
		for (j = 2; j <= n; j++)
		for (i = 1; i <= n; i++)
			sum[i][j] = sum[i%n + 1][j - 1] + num[i];
		for (i = 0; i <= n; i++)
			dp1[i][1] = dp2[i][1] = 0;
		for (j = 2; j <= n; j++)
		{
			for (i = 1; i <= n; i++)
			{
				dp1[i][j] = 0;
				dp2[i][j] = INF;
				for (k = 1; k<j; k++)
				{
					dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[(i + k - 1) % n + 1][j - k] + sum[i][j]);
					dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[(i + k - 1) % n + 1][j - k] + sum[i][j]);
				}
			}
		}
		int ansmi = INF, ansmx = 0;
		for (i = 1; i <= n; i++)
		{
			ansmx = max(ansmx, dp1[i][n]);
			ansmi = min(ansmi, dp2[i][n]);
		}
		printf("%d\n%d\n", ansmi, ansmx);
	}
	
	system("pause");
	return 0;
}