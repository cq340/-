#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
	int n;//n����ͧ����վ
	int r[300][300];
	while (scanf("%d", &n) == 1){
		for (int i = 1; i < n;i++)
		for (int j = i+1; j <= n ; j++)
			cin >> r[i][j];//�������
		for (int i = 2; i < n;i++)
		for (int j = 1; j<= n-i;j++)
		for (int k = j + 1; k < j + i; k++)
		{
			r[j][j + i] = min(r[j][k] + r[k][j + i], r[j][j + i]);  //��̬�滮
		}
		cout << "���Ϊ"<<r[1][n];
	}
	return 0;
}