#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long n, r;
	long long y = 0;
	while (cin >> n >> r)
	{
		y = 6.28*r;
		if (n<y)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}