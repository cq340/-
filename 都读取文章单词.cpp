#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int a[100],n,sum;
	cin >> n>>sum;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int begin = 0,end=n-1;
	for (int j = 0; j < n; j++)
	{
		if (a[begin] + a[end]>sum)
			end--;
		else if (a[begin] + a[end] < sum)
			begin++;
		else
		{
			cout << a[begin] << " " << sum - a[end];
			return 0;
		}
	}
	cout << "mmeizhoaoda";
	return 0;
}