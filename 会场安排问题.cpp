#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define SIZE 10005
 
struct Activity_Info
{
	int s;	//��ʼʱ��
	int e;	//����ʱ��
	int flag;
}acts[SIZE];

bool Cmp(const Activity_Info a, const Activity_Info b)
{
	return a.s < b.s;
	if (a.s == b.s)
		return a.e < b.e;
}

int ArrangingActivities(int n)
{
	//����ʼʱ���С��������
	sort(acts, acts + n, Cmp);
	for (int i = 0; i < n; i++)
		acts[i].flag = 0;
	int count = 1;
	//int currTime = acts[0].e;	//��ǰʱ��
	int i,j;
	acts[0].flag = 1;
	for (i = 1; i <n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (acts[j].flag&&acts[j].e<=acts[i].s)
			{
			    acts[i].flag = acts[j].flag;
				acts[j].flag = 0;//�Ѿ����Ź��û���ٱȽ�
				break;
			}
		}
		if (i == j)
		{
			count++;
			acts[i].flag = count;
		}

	}
	cout <<endl<<"���ٳ���Ϊ"<< count << endl;
	return count;
}

int main(void)
{

	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &acts[i].s, &acts[i].e);
	}

	 ArrangingActivities(n);
	system("pause");
	return 0;
}
