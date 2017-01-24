#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<map>

using  namespace std;

int main(void)
{
	char buffer[256];
	ifstream inputFile("input.txt");
	ofstream outFile("output.txt");
	//�ж��Ƿ���ȷ��ȡ�����ļ�
	if (!inputFile){
		cout << "Unable to open inputFile";
		exit(1);
	}
	//�ж��Ƿ���ȷ������ļ�
	if (!outFile){
		cout << "Unable to open outFile";
		exit(1); // 
	}
	long data[1000];
	long max = 0, key;
	for (int i = 0; !inputFile.eof(); i++)
	{
		//��ȡ�����ļ�
		inputFile.getline(buffer, 10);
		sscanf(buffer, "%d ", &data[i]);
	}

	//����mapӳ��
	map<long, long> cnt;
	for (int j = 1; j <= data[0]; j++)
	{
		//���map�в�����data[j],�Ȱ�cnt��ֵΪ0�������ӣ�����ֱ������
		if (!cnt[data[j]])
			cnt[data[j]] = 0;
		    cnt[data[j]]++;
		//������������data[j]
		if (cnt[data[j]] > max)
		{
			max = cnt[data[j]];
			key = data[j];
		}
	}
	cout << "Ԫ������Ϊ��" << data[0] << endl;
	
	if (max > data[0] / 2)
	{
		cout << "��Ԫ������Ϊ��" << max << endl;
		cout << "��Ԫ��Ϊ��" <<key << endl;
		outFile << "��Ԫ��Ϊ:" << key << endl;
	}
	else
	{
		cout << "��������Ԫ��,��Ԫ��Ϊ:null" << endl;
		outFile << "��Ԫ��Ϊ:null" << endl;
	}

	inputFile.close();
	outFile.close();
	system("pause");
	return 0;
}

