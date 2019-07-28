#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	//int n;
	//cin >> n;
	//n = abs(n);
	//int old = n;
	//int x = 0;
	//while (n>0)
	//{
	//	x = x * 10 + n % 10;
	//	n /= 10;
	//}
	//if (old == x)
	//	cout << "Yes" << endl;
	//else
	//	cout << "No" << endl;
	//return 0;
	int n;
	while (cin >> n)
	{
		n = abs(n);
		int help = 1;
		while (n / help > 10)
			help *= 10;
		while (n!=0)
		{
			if (n % 10 != n / help)
			{
				cout << "No" << endl;
				goto x;
			}
			n = (n%help) / 10;
			help /= 100;
		}
		cout << "Yes" << endl;
	x:;
	}
	return 0;
}