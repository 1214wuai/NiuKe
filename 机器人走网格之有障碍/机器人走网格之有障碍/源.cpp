#include<iostream>
#include<vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid)
{
	if (obstacleGrid.empty())
		return 0;
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> paths(m, vector<int>(n, 0));
	//初始化   F(0,0)
	//第一列初始化
	for (int i = 0; i < m; i++)
	{
		if (obstacleGrid[i][0])
			break;
		else
			paths[i][0] = 1;
	}
	//第一行
	for (int i = 0; i < n; i++)
	{
		if (obstacleGrid[0][i])
			break;
		else
			paths[0][i] = 1;
	}
	//递推
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j])
				paths[i][j] = 0;
			else
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
		}
	}
	return paths[m - 1][n - 1];
}
int main()
{
	vector<vector<int>> obstaclesGrid = { {0,0,0},{0,1,0},{0,0,0} };
	cout << uniquePathsWithObstacles(obstaclesGrid) << endl;
	system("pause");
	return 0;
}