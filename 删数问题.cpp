#include<iostream>
#include<algorithm>
using namespace std;

string delete_num(string s,int k)
{
	int m = s.size();
	if (k >= m)
	{
		s.erase();
		return NULL;
	}
	while (k > 0)
	{
		int i ;
	for ( i = 0; s[i] <=s[i + 1] && i <= m - 2; i++);
	s.erase(i, 1);
	k--;
	}
	while (s.size() > 1 && s[0] == '0')
		s.erase(0, 1);
	return s;
}

int main()
{
	string s = "23241241889";
	string str= delete_num(s, 5);
	printf_s("%s", str);
	system("pause");
	return 0;
}
