#include<iostream>
#include<algorithm>
using namespace std;



class Animal
{
public:
	void shout()const
	{
		cout << "我是动物！" << endl;
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

	//delete animals;// 编译正确，执行出错；
	//delete[] animals;//正确，执行时构造器和析构器都是10次。
	double d = 3.2; int n = 3;
	A *p = new B();
	delete p;

	//cout << (d - 0.2) | n;

	system("pause");
	return 0;
}