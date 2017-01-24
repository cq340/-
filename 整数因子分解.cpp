#include "iostream"
#include "algorithm"
#include "fstream"
using namespace std;

/*
h(n)Ϊn�Ļ�����
h(1) = 1
h(2) = 1
h(n) = h(n/2) + h(n/3) + ... + h(n/n)  ǰ�����ܱ�����
*/

int h[100];

//��̬�滮
int solve(int n)
{
	h[1] = 1;
	h[2] = 1;
	for (int i = 3; i <= n; i++)
	for (int j = 2; j <= i; j++)
	if (i%j == 0) //���j�ܱ�i����
		h[i] += h[i / j];
	return  h[n];
}

//�ݹ�
int total = 0;
int recursive(int n)
{
	if (n == 1 || n == 2)
		return 1;
	for (int i = 3; i <= n; i++)
	if (n%i == 0)
		total += recursive(n / i);
	return total;
}

int main()
{
	int n;
	cout << "��������������";
	cin >> n;
	int count = solve(n);
	//cout << "�ֽ�ʽ������Ϊ����̬�滮����";
	cout << count << endl;
	cout << "�ֽ�ʽ������Ϊ���ݹ飩��";
    count = recursive(n);
	cout << count << endl;
	system("pause");
	return 0;
}