#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define EMPTY 0
#define MALE 1
#define FEMALE 2
#define NUM  7                  //ʯͷ����
#define MAXSTEP  20             //��Ϸ����ɹ�������Ҫ����Ծ����

//static int stone[]={MALE,MALE,MALE,EMPTY,FEMALE,FEMALE,FEMALE};  //��ʼ����Ϸ״̬
static int stone[] = { MALE, MALE, MALE, EMPTY, FEMALE, FEMALE, FEMALE };
static int step[MAXSTEP];  //��ʼ����Ծ�����step[i]��ʾ��i����λ����λ�����ܽ�������Ծ

void myprint();
bool AdjacRule(int posi, int emptyPosi);
bool isProperLeap(int posi, int emptyPosi);
bool isSuccess();
int whereEmpty();
void frogLeap(int floor);

void main()
{
	for (int i = 0; i < MAXSTEP; i++)
		step[i] = -1;

	frogLeap(0);

	getchar();



}


void frogLeap(int floor)
{
	
	int emptyPosi = whereEmpty();
	int i;

	if (isSuccess())
		myprint();
	else
	{
	
		for (i = emptyPosi - 2; i <= emptyPosi + 2; i++) //�ӿ�λ���Եĸ���ֻ����(����Ǹ���ֻ)���п���
		{
			if (i >= 0 && i <= 6 && i != emptyPosi)
			{
				if (isProperLeap(i, emptyPosi))     //isProperLeap��legalleap and unAdjacentleap
				{
					int n = floor;
					swap(stone[i], stone[emptyPosi]);
					step[n] = i;
					frogLeap(n + 1);
					swap(stone[i], stone[emptyPosi]);
					
				}
			}
		}
	}
}

/** ������λΪ��
*/
int whereEmpty()
{
	for (int i = 0; i < NUM; i++)
	{
		if (stone[i] == EMPTY)
		{
			return i;
		}
	}
	return -1;
}

/** �ж���Ϸ�Ƿ�ɹ�
*/
bool isSuccess()
{

	int i;
	int compare[] = { FEMALE, FEMALE, FEMALE, EMPTY, MALE, MALE, MALE };
	for (i = 0; i < NUM; i++)
	{
		if (stone[i] != compare[i])
			break;
	}

	if (i == NUM)
		return true;
	else
		return false;
}

/** �ж�λ��Ϊposi�������Ƿ������
�����ж�׼��
1.�����ǲ��Ƕԣ�������ĸ����
2.�ǲ��Ƿ��ϼ�֦����(������������Ծ��û�����ڵ�ͬ������)
*/
bool isProperLeap(int posi, int emptyPosi)
{
	//	bool flag=isnotAdjacent(posi,emptyPosi);

	if (stone[posi] == MALE)
	{
		if ((posi<emptyPosi) && AdjacRule(posi, emptyPosi))
		{
			return true;
		}
		else
			return false;

	}
	else if (stone[posi] == FEMALE)
	{
		if ((posi>emptyPosi) && AdjacRule(posi, emptyPosi))
			return true;
		else
			return false;
	}

	return false;


}

/** �ж�λ��Ϊposi�������Ƿ������
�����ж�׼��
1.�����ǲ��Ƕԣ�������ĸ����
2.�ǲ��Ƿ��ϼ�֦����(������������Ծ��û�����ڵ�ͬ������)
*/
bool AdjacRule(int posi, int emptyPosi)
{
	swap(stone[posi], stone[emptyPosi]);
	if (emptyPosi == 0 || emptyPosi == 6)
	{
		swap(stone[posi], stone[emptyPosi]);
		return true;
	}
	if (emptyPosi == 1)
	{
		if (stone[0] == FEMALE&&stone[1] == FEMALE&&stone[2] == FEMALE)
		{
			swap(stone[posi], stone[emptyPosi]);
			return true;
		}
		else if (stone[0] == FEMALE&&stone[1] == FEMALE)
		{
			swap(stone[posi], stone[emptyPosi]);
			return true;
		}
		else if (stone[1] != stone[2])
		{
			swap(stone[posi], stone[emptyPosi]);
			return true;
		}
	}
	if (emptyPosi == 5)
	{
		if (stone[4] == MALE&&stone[5] == MALE&&stone[6] == MALE)
		{
			swap(stone[posi], stone[emptyPosi]);
			return true;
		}
		else if (stone[5] == MALE&&stone[6] == MALE)
		{
			swap(stone[posi], stone[emptyPosi]);
			return true;
		}
		else if (stone[4] != stone[5])
		{
			swap(stone[posi], stone[emptyPosi]);
			return true;
		}
	}
	if (emptyPosi == 2)
	{
		bool i = false;
		if (stone[0] == FEMALE&&stone[1] == FEMALE&&stone[2] == FEMALE)
			i = true;
		else if (stone[2] != stone[1] && stone[2] != stone[3])
			i = true;

		swap(stone[posi], stone[emptyPosi]);
		if (i)
			return true;
		else if (!i)
			return false;


	}
	if (emptyPosi == 4)
	{
		bool i = false;
		if (stone[4] == MALE&&stone[5] == MALE&&stone[6] == MALE)
			i = true;
		else if (stone[4] != stone[3] && stone[4] != stone[5])
			i = true;

		swap(stone[posi], stone[emptyPosi]);
		if (i)
			return true;
		else if (!i)
			return false;
	}
	if (emptyPosi == 3)
	{
		bool i = false;
		if (stone[3] != stone[4] && stone[3] != stone[2])
			i = true;

		swap(stone[posi], stone[emptyPosi]);
		if (i)
			return true;
		else if (!i)
			return false;
	}

	swap(stone[posi], stone[emptyPosi]);
	return false;

}

void myprint()
{
	int i = 0;
	cout << "Ҫ��Ծ����λ��˳������:";
	while (step[i] != -1)
	{
		cout << step[i] << " ";
		i++;
	}
	cout << endl;
}

bool maleCan()
{
	bool i = (stone[5] == MALE&&stone[6] == MALE);
	bool j = (stone[4] == MALE&&stone[5] == MALE&&stone[6] == MALE);
	if (i&&j)
		return true;
	else
		return false;
}
bool femaleCan()
{
	bool i = (stone[0] == FEMALE&&stone[0] == FEMALE);
	bool j = (stone[0] == FEMALE&&stone[1] == FEMALE&&stone[2] == FEMALE);
	if (i&&j)
		return true;
	else
		return false;
}