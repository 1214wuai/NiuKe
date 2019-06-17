#include<iostream>
#include<vector>

using namespace std;

int uniquePaths(int m, int n)
{
	if (m < 1 || n < 1)
		return 0;
	//³õÊ¼»¯  F(0,i) = F(i,0) = 1;
	vector<vector<int>> path(m, vector<int>(n, 1));
	//µÝÍÆ
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			path[i][j] = path[i - 1][j] + path[i][j - 1];
		}
	}
	return path[m - 1][n - 1];
}
int main()
{
	cout << uniquePaths(5,5) << endl;
	system("pause");
	return 0;
}
