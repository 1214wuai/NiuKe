#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v = { 2,5,3,10,4 };
	vector<int> w = { 1,3,2,6,2 };
	int total = 12;
	int vsz = v.size();
	int wsz = w.size();

	vector<vector<int>> ret(vsz + 1, vector<int>(total + 1, 0));
	for (int i = 1; i <= vsz; i++)
	{
		for (int j = 1; j <= total; j++)
		{
			if (j >= w[i-1])
				ret[i][j] = max(ret[i - 1][j], (ret[i - 1][j - w[i-1]] + v[i-1]));
			else
				ret[i][j] = ret[i - 1][j];
		}
	}
	for (int i = 0; i <= vsz; i++)
	{
		for (int j = 0; j <= total; j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
