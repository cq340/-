#include<iostream>
#include<cstring>
#include<algorithm>
#define Num 1000
using namespace std;

int Get_min_coins(int coins[], int value)
{
	int d[Num];  //动态数组用来存储最少数量
	d[0] = 0;
	for (int i = 1; i < Num; i++)
		d[i] = value+10;    //初始化赋值，只要比value值大就行，但是也不能数值越界
	for (int i = 1; i <= value;i++)
	for (int j = 0; j < 4; j++)  //硬币种类
	{
		if (coins[j]<=i&&d[i]>d[i - coins[j]] + 1)
		{
			d[i] = d[i - coins[j]] + 1;   //动规
		
		}
	}
	return d[value];   //返回数量
}

int main(){
    int  coins[5] = { 1, 2, 5, 10 };// 硬币的面值
	int value;  //要兑换硬币的数值
	cout << "请输入要兑换硬币的数值：" << endl;
	while (cin >> value){
		int min = Get_min_coins(coins,value);  
		cout <<"最少需要"<< min<<"枚硬币" << endl;
		cout << "请输入要兑换硬币的数值：" << endl;
	}
}