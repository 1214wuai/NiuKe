#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int FindMinBoard(vector<vector<int>> & board)
{
	if (board.empty())
		return 0;
	int m = board.size();
	int n = board[0].size();
	vector<vector<int>> min_sum(m, vector<int>(n, 0));
	//≥ı ºªØ
	min_sum[0][0] = board[0][0];
	for (int i = 1; i < m; i++)
		min_sum[i][0] = board[i][0]+min_sum[i-1][0];
	for (int i = 1; i < n; i++)
		min_sum[0][i] = board[0][i]+min_sum[0][i-1];
	//µ›Õ∆
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i][j - 1]) + board[i][j];
		}
	}
	return min_sum[m - 1][n - 1];
}
int main()
{
	vector<vector<int>> board{ {1,2,3},{4,5,6},{7,8,9} };
	cout << FindMinBoard(board) << endl;
	system("pause");
	return 0;
}