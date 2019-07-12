#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int minDistance(string word1, string word2)
{
	if (word1.empty() || word2.empty())
		return max(word1.size(), word2.size());

	int m = word1.size();
	int n = word2.size();
	vector<vector<int>> min_dis(m + 1, vector<int>(n + 1, 0));
	//初始化 F(i,0) F(0,i)
	for (int i = 0; i < m + 1; i++)
		min_dis[i][0] = i;
	for (int i = 0; i < n + 1; i++)
		min_dis[0][i] = i;
	//递推
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			//F(i,j)=min{F(i,j-1)+1，F(i-1,j)+1, F(i-1,j-1)+((w1[i]==w2[j])?0:1)}    插入 删除 替换
			min_dis[i][j] = min(min_dis[i - 1][j], min_dis[i][j - 1]) + 1;
			if (word1[i - 1] == word2[j - 1])
				min_dis[i][j] = min(min_dis[i][j], min_dis[i - 1][j - 1]);
			else
				min_dis[i][j] = min(min_dis[i][j], min_dis[i - 1][j - 1]+1);
		}
	}
	//返回结果
	return min_dis[m][n];
}
int main()
{

	cout << minDistance("haha", "hehe") << endl;
	system("pause");
	return 0;
}