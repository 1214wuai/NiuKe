#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		int count = 0;
		while (n>1)
		{
			n /= 2;
			count++;
		}

		cout << count << endl;
	}
}