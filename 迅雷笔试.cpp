#include<iostream>
#include<algorithm>
using namespace std;



class Animal
{
public:
	void shout()const
	{
		cout << "���Ƕ��" << endl;
	}
	~Animal()
	{
		cout << "Destructor Animal!" << endl;
	}
};

class A
{
public:
	~A();
};
A::~A()
{
	printf("delete A ");
}

class B : public A
{
public:
	~B();
};
B::~B()
{
	printf("delete B ");
}

int main()
{

	Animal *animals = new Animal[10];

	//delete animals;// ������ȷ��ִ�г���
	//delete[] animals;//��ȷ��ִ��ʱ������������������10�Ρ�
	double d = 3.2; int n = 3;
	A *p = new B();
	delete p;

	//cout << (d - 0.2) | n;

	system("pause");
	return 0;
}