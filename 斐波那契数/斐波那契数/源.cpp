#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n<4)
			cout << n << endl;
		else
		{
			long long a = 2;
			long long b = 3;
			long long ret = 0;
			for (int i = 3; i<n; i++)
			{
				ret = a + b;
				a = b;
				b = ret;
			}
			if (ret>99999)
				cout << (ret & 99999)<< endl;
			else
				cout << ret << endl;
		}
	}
	return 0;
}