//װ������ ���ȶ���ʽ��֧�޽編��� 

#include "MaxHeap.h"
#include <iostream>
using namespace std;

const int N = 4;

class bbnode;

template<class Type>
class HeapNode
{
	template<class Type>
	friend void AddLiveNode(MaxHeap<HeapNode<Type>>& H, bbnode *E, Type wt, bool ch, int lev);
	template<class Type>
	friend Type MaxLoading(Type w[], Type c, int n, int bestx[]);
public:
	operator Type() const{ return uweight; }
private:
	bbnode *ptr;		//ָ���ڵ����Ӽ�������Ӧ�ڵ��ָ��
	Type uweight;		//��ڵ����ȼ�(�Ͻ�)
	int level;			//��ڵ����Ӽ����������Ĳ����
};

class bbnode
{
	template<class Type>
	friend void AddLiveNode(MaxHeap<HeapNode<Type>>& H, bbnode *E, Type wt, bool ch, int lev);
	template<class Type>
	friend Type MaxLoading(Type w[], Type c, int n, int bestx[]);
	friend class AdjacencyGraph;

private:
	bbnode *parent;		//ָ�򸸽ڵ��ָ��
	bool LChild;		//����ӽڵ��ʶ
};

template<class Type>
void AddLiveNode(MaxHeap<HeapNode<Type>>& H, bbnode *E, Type wt, bool ch, int lev);

template<class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[]);


int main()
{
	float c = 70;
	float w[] = { 0, 20, 10, 26, 15 };//�±��1��ʼ  
	int x[N + 1];
	float bestw;

	cout << "�ִ�����Ϊ��" << c << endl;
	cout << "��װ��Ʒ�������ֱ�Ϊ��" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	bestw = MaxLoading(w, c, N, x);

	cout << "��֧�޽�ѡ����Ϊ:" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
	cout << "����װ������Ϊ��" << bestw << endl;
	system("pause");
	return 0;
}

//����ڵ���뵽��ʾ��ڵ����ȶ��е�����H��
template<class Type>
void AddLiveNode(MaxHeap<HeapNode<Type>>& H, bbnode *E, Type wt, bool ch, int lev)
{
	bbnode *b = new bbnode;
	b->parent = E;
	b->LChild = ch;
	HeapNode<Type> N;

	N.uweight = wt;
	N.level = lev;
	N.ptr = b;
	H.Insert(N);
}

//���ȶ���ʽ��֧�޽編������������������bestx�������Ž�
template<class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[])
{
	//������������Ϊ1000
	MaxHeap<HeapNode<Type>> H(1000);

	//����ʣ����������
	Type *r = new Type[n + 1];
	r[n] = 0;

	for (int j = n - 1; j>0; j--)
	{
		r[j] = r[j + 1] + w[j + 1];
	}

	//��ʼ��
	int i = 1;//��ǰ��չ�ڵ������Ĳ�
	bbnode *E = 0;//��ǰ��չ�ڵ�
	Type Ew = 0; //��չ�ڵ�����Ӧ��������

	//�����Ӽ��ռ���
	while (i != n + 1)//��Ҷ�ӽڵ�
	{
		//��鵱ǰ��չ�ڵ�Ķ��ӽڵ�
		if (Ew + w[i] <= c)
		{
			AddLiveNode(H, E, Ew + w[i] + r[i], true, i + 1);
		}
		//�Ҷ��ӽڵ�
		AddLiveNode(H, E, Ew + r[i], false, i + 1);

		//ȡ��һ��չ�ڵ�
		HeapNode<Type> N;
		H.DeleteMax(N);//�ǿ�
		i = N.level;
		E = N.ptr;
		Ew = N.uweight - r[i - 1];
	}

	//���쵱ǰ���Ž�
	for (int j = n; j>0; j--)
	{
		bestx[j] = E->LChild;
		E = E->parent;
	}

	return Ew;
}