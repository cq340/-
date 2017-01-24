
void MinHeapFixup(int a[], int i)
{
	int j, temp;
	temp = a[i];
	j = (i - 1) / 2;//���ڵ�
	while (j > 0 && i != 0)
	{
		if (a[j] <= temp)
			break;
		a[i] = a[j];
		i = j;
		j = (i - 1) / 2;

	}
	a[i] = temp;
}

void MinHeapAddnumber(int a[], int n, int nNum)
{
	a[n] = nNum;
	MinHeapFixup(a, n);
}

//  ��i�ڵ㿪ʼ����,nΪ�ڵ����� ��0��ʼ���� i�ڵ���ӽڵ�Ϊ 2*i+1, 2*i+2
void MinHeapFixdown(int a[], int i, int n)
{
	int j, temp;

	temp = a[i];
	j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1 < n && a[j + 1] < a[j]) //�����Һ���������С��
			j++;

		if (a[j] >= temp)
			break;

		a[i] = a[j];     //�ѽ�С���ӽ�������ƶ�,�滻���ĸ����
		i = j;
		j = 2 * i + 1;
	}
	a[i] = temp;
}
//����С����ɾ����
void MinHeapDeleteNumber(int a[], int n)
{
	Swap(a[0], a[n - 1]);
	MinHeapFixdown(a, 0, n - 1);
}