#include<iostream>
#include<cstring>
#include<algorithm>
#define Num 1000
using namespace std;

int Get_min_coins(int coins[], int value)
{
	int d[Num];  //��̬���������洢��������
	d[0] = 0;
	for (int i = 1; i < Num; i++)
		d[i] = value+10;    //��ʼ����ֵ��ֻҪ��valueֵ����У�����Ҳ������ֵԽ��
	for (int i = 1; i <= value;i++)
	for (int j = 0; j < 4; j++)  //Ӳ������
	{
		if (coins[j]<=i&&d[i]>d[i - coins[j]] + 1)
		{
			d[i] = d[i - coins[j]] + 1;   //����
		
		}
	}
	return d[value];   //��������
}

int main(){
    int  coins[5] = { 1, 2, 5, 10 };// Ӳ�ҵ���ֵ
	int value;  //Ҫ�һ�Ӳ�ҵ���ֵ
	cout << "������Ҫ�һ�Ӳ�ҵ���ֵ��" << endl;
	while (cin >> value){
		int min = Get_min_coins(coins,value);  
		cout <<"������Ҫ"<< min<<"öӲ��" << endl;
		cout << "������Ҫ�һ�Ӳ�ҵ���ֵ��" << endl;
	}
}