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
	//判断是否正确读取输入文件
	if (!inputFile){
		cout << "Unable to open inputFile";
		exit(1);
	}
	//判断是否正确打开输出文件
	if (!outFile){
		cout << "Unable to open outFile";
		exit(1); // 
	}
	long data[1000];
	long max = 0, key;
	for (int i = 0; !inputFile.eof(); i++)
	{
		//读取输入文件
		inputFile.getline(buffer, 10);
		sscanf(buffer, "%d ", &data[i]);
	}

	//利用map映射
	map<long, long> cnt;
	for (int j = 1; j <= data[0]; j++)
	{
		//如果map中不存在data[j],先把cnt赋值为0，再增加，否则直接增加
		if (!cnt[data[j]])
			cnt[data[j]] = 0;
		    cnt[data[j]]++;
		//保存数量最多的data[j]
		if (cnt[data[j]] > max)
		{
			max = cnt[data[j]];
			key = data[j];
		}
	}
	cout << "元素数量为：" << data[0] << endl;
	
	if (max > data[0] / 2)
	{
		cout << "主元素数量为：" << max << endl;
		cout << "主元素为：" <<key << endl;
		outFile << "主元素为:" << key << endl;
	}
	else
	{
		cout << "不存在主元素,主元素为:null" << endl;
		outFile << "主元素为:null" << endl;
	}

	inputFile.close();
	outFile.close();
	system("pause");
	return 0;
}

