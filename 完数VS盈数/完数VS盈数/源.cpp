//一个数如果恰好等于它的各因子(该数本身除外)子和，如：6 = 3 + 2 + 1。则称其为“完数”；
//若因子之和大于该数，则称其为“盈数”。 求出2到60之间所有“完数”和“盈数”。
//输出2到60之间所有“完数”和“盈数”，并以如下形式输出：
//E : e1 e2 e3 ......(ei为完数)
//G : g1 g2 g3 ......(gi为盈数)
//其中两个数之间要有空格，行尾不加空格。

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>e;
	vector<int>g;
	for (int n = 2; n <= 60; n++)
	{
		int sum = 0;
		for (int j = 1; j<n; j++)
		{
			if (n%j == 0)
				sum += j;
		}
		if (sum == n)
		{
			e.push_back(n);
		}
		if (sum > n)
		{
			g.push_back(n);
		}
	}
	cout << "E:";
	for (int i = 0; i < e.size(); i++)
	{
		cout << " " << e[i];
	}
	cout << endl;
	cout << "G:";
	for (int i = 0; i < g.size(); i++)
	{
		cout << " " << g[i];
	}
	return 0;
}