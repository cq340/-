#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 9999

using namespace std;
//����ÿ���ļ�����ȡ�ĸ���
int calculate(int n, int gailv[], double gailv1[])

{
	int sum = 0;
	int i;
	for (i = 0; i<n; i++)
	{
		sum += gailv[i];
	}
	for (i = 0; i<n; i++)
	{
		gailv1[i] = (double)gailv[i] / sum;
	}
	return 0;
}
//�����ļ��Ͷ�ȡ���ʵĳ˻�
int multiple(int n, double gailv1[], int length[], double length1[])
{
	int i;
	for (i = 0; i<n; i++)
	{
		length1[i] = ((double)gailv1[i])*((double)length[i]);
	}
	return 0;
}

//��ȡÿ���������õ�ʱ��
int add(int n, double length1[], double sum[])
{
	double t=0;
	for (int i = 0; i<n; i++)
	{
		t+= length1[i];
		sum[i] = t;
	}
	return 0;
}
//��ȡ���г����ƽ��ʱ��
int Min_time(int n, double sum[])
{
	int i;
	double min_time = 0.0;
	for (i = 0; i<n; i++)
	{
		min_time += sum[i];
	}
	printf("��Сƽ����ȡʱ��Ϊ��\n");
	printf("%f\n", min_time);
	return 0;
}


int main()
{
	int n, i;
	int length[N];
	int gailv[N];
	double gailv1[N];
	double length1[N];
	double sum[N];
	scanf("%d", &n);//�����ļ�������
	for (i = 0; i<n; i++)
	{
		scanf("%d%d", &length[i],&gailv[i]);//���� �ļ��ĳ��ȺͶ�ȡ����
	}
	calculate(n, gailv, gailv1);
	multiple(n, gailv1, length, length1);
	sort(length1, length1+n);
	add(n, length1, sum);
	Min_time(n, sum);
	system("pause");
	return 0;
}