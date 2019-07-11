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
	//��ʼ��  F(0,0) = (0,0)
	min_sum[0][0] = triangle[0][0];
	//״̬����
	for (int i = 1; i<line; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			//��߽�
			if (j == 0)
				min_sum[i][j] = min_sum[i - 1][j] + triangle[i][j];
			//�ұ߽�
			else if (j == i)
				min_sum[i][j] = min_sum[i - 1][j - 1] + triangle[i][j];
			else
				min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i - 1][j - 1]) + triangle[i][j];
		}
	}
	//���ؽ��
	int result = min_sum[line - 1][0];
	for (int i = 1; i<line; i++)
		result = min(result, min_sum[line - 1][i]);
	return result;
}

int minimumTotalV2(vector<vector<int>> &triangle)
{
	if (triangle.empty())
		return 0;
	vector<vector<int>> min_sum(triangle);
	int line = triangle.size();
	//��ʼ��
	for (int i = 0; i < line; i++)
		min_sum[line - 1][i] = triangle[line - 1][i];
	//����
	for (int i = line - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			//F(i,j) = min(F(i+1,j), F(i+1,j+1))+(i,j)
			min_sum[i][j] = min(min_sum[i + 1][j], min_sum[i + 1][j + 1]) + triangle[i][j];
		}
	}
	//���ؽ��
	return min_sum[0][0];
}
int main()
{
	vector<vector<int>> triangle = { { 2 },{ 3,4 },{ 6,5,7 },{ 4,1,8,3 } };
	cout << minimumTotal(triangle) << endl;
	cout << minimumTotalV2(triangle) << endl;
	system("pause");
	return 0;
}