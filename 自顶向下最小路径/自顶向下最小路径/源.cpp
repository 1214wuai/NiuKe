#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimumTotal(vector<vector<int>> &triangle)
{
	if (triangle.empty())
		return 0;
	vector<vector<int>> min_sum(triangle);
	int line = triangle.size();
	//初始化  F(0,0) = (0,0)
	min_sum[0][0] = triangle[0][0];
	//状态递推
	for (int i = 1; i<line; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			//左边界
			if (j == 0)
				min_sum[i][j] = min_sum[i - 1][j] + triangle[i][j];
			//右边界
			else if (j == i)
				min_sum[i][j] = min_sum[i - 1][j - 1] + triangle[i][j];
			else
				min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i - 1][j - 1]) + triangle[i][j];
		}
	}
	//返回结果
	int result = min_sum[line - 1][0];
	for (int i = 1; i<line; i++)
		result = min(result, min_sum[line - 1][i]);
	return result;
}
int main()
{
	vector<vector<int>> triangle = { { 2 },{ 3,4 },{ 6,5,7 },{ 4,1,8,3 } };
	cout << minimumTotal(triangle) << endl;
	system("pause");
	return 0;
}