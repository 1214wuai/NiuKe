#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(int n)
{
	if (n <= 1 || n>66)
		return 0;
	if (n == 2)
		return 0;
	if (n == 3)
		return 3;
	vector<int> v(n+1, 0);
	v[3] = 3;
	v[4] = 8;
	v[5] = 45;
	for (int i = 1; i < n+1; i++)
	{
		v[i] = i * (i - 2)*v[i-2];
	}
	return v[n];
}
int main()
{
	int n;
	while (cin >> n)
	{	
		cout << f(n) << endl;
	}
}

//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		if (n < 1)
//			return 0;
//		vector<int> v(n, 0);//分数
//		vector<int> w(n, 0);//时间
//		for (int i = 0; i < n; i++)
//			cin >> v[i];
//		for (int i = 0; i < n; i++)
//			cin >> w[i];
//		int total;
//		cin >> total;
//		vector<vector<int>> ret(n + 1, vector<int>(total + 1, 0));
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= total; j++)
//			{
//				if (j >= w[i - 1])
//					ret[i][j] = max(ret[i - 1][j], (ret[i - 1][j - w[i - 1]] + v[i-1]));
//				else
//					ret[i][j] = ret[i - 1][j];
//			}
//		}
//		cout << ret[n][total] << endl;
//
//
//	}
//	return 0;
//}