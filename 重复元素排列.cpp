#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int n = 0;//ͳ��ȫ���и���
ofstream out("output.txt");

// ����  
template<class Type>
void Swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}

// �ж��Ƿ����ظ�Ԫ�ؽ���
template<class Type>
bool isSwap(Type list[], int k, int m)
{
	for (int i = k; i < m; i++)
	if (list[i] == list[m])
		return false;
	return true;
}

//ȫ���У�ÿ��ֻȡһ��������Perm(r1)��ʾPerm�в���r1��������r1��ͷ��  
template<class Type>
void Perm(Type list[], int k, int m)
{ // ����list[k:m]����������  
	if (k == m)
	{ // ֻʣ��һ��Ԫ��  
		for (int i = 0; i <= m; i++)
		{
			out << list[i];
		}
		out << endl;
		n++;
	}
	else
	{ // ���ж��Ԫ�ش����У��ݹ��������  
		for (int i = k; i <= m; i++)
		{
			if (isSwap(list, k, i))
			{ // �ж��Ƿ�Ϊ�ظ�Ԫ�ؽ���
				Swap(list[k], list[i]);
				Perm(list, k + 1, m);
				Swap(list[k], list[i]);
			}
		}
	}
}

int main()
{
	ifstream in("input.txt");
	if (!in)
	{
		cout << "In Error!" << endl;
		exit(-1);
	}
	if (!out)
	{
		cout << "Out Error!" << endl;
		exit(-1);
	}
	int l;
	in >> l;
	char* a = new char[l];
	in.get();
	for (int i = 0; i < l; i++)
	{
		in >> a[i];
	}
	Perm(a, 0, l - 1);
	out << n << endl;
	in.close();
	out.close();
	return 0;
}