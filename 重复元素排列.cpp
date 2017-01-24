#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int n = 0;//统计全排列个数
ofstream out("output.txt");

// 交换  
template<class Type>
void Swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}

// 判断是否是重复元素交换
template<class Type>
bool isSwap(Type list[], int k, int m)
{
	for (int i = k; i < m; i++)
	if (list[i] == list[m])
		return false;
	return true;
}

//全排列，每次只取一个出来，Perm(r1)表示Perm中不含r1，并且由r1开头。  
template<class Type>
void Perm(Type list[], int k, int m)
{ // 产生list[k:m]的所有排列  
	if (k == m)
	{ // 只剩下一个元素  
		for (int i = 0; i <= m; i++)
		{
			out << list[i];
		}
		out << endl;
		n++;
	}
	else
	{ // 还有多个元素待排列，递归产生排列  
		for (int i = k; i <= m; i++)
		{
			if (isSwap(list, k, i))
			{ // 判断是否为重复元素交换
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