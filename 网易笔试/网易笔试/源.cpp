#include<iostream>
#include<vector>
#include<string>
using namespace std;
//bool IsOK(vector<vector<int>> v, vector<int> v1,int rows, int cols, int row, int col)
//{
//
//	for (int i = row; i < (row + v1[0]); i++)
//	{
//		for (int j = col; j < (col + v1[1]); j++)
//		{
//			if (i == row + v1[0] - 1 && j == col + v1[1] - 1 && v[i][j] == 1)
//				return true;
//			else if (i < rows  && j < cols  && v[i][j] == 1)
//				continue;
//			else
//				return false;
//		}
//	}
//	return true;
//
//}
//int main()
//{
//	int t;
//	vector<string> str;
//	cin >> t;
//	while (t--)
//	{
//		vector<int> v1;
//		v1.resize(3);
//		for (int i = 0; i<3; i++)
//			cin >> v1[i];
//		vector<vector<int>> v2;//障碍物的位置
//		v2.resize(v1[2]);
//		for (int i = 0; i < v1[2]; i++)
//		{
//			v2[i].resize(2);
//			cin >> v2[i][0] >> v2[i][1];
//		}
//		vector<int> v3;//货物大小
//		v3.resize(2);
//		cin >> v3[0] >> v3[1];
//
//		vector<vector<int>> v4;//整个广场
//		v4.resize(v1[0]);
//		for (int i = 0; i < v1[0]; i++)
//		{
//			v4[i].resize(v1[1]);
//			for (int j = 0; j < v1[1]; j++)
//				v4[i][j] = 1;
//		}
//		for (int i = 0; i < v2.size(); i++)
//		{
//			v4[v2[i][0] - 1][v2[i][1] - 1] = 0;//放障碍物
//		}
//		int rows = v4.size();
//		int cols = v4[0].size();
//		for (int i = 0; i < v4.size(); i++)
//		{
//			for (int j = 0; j < v4[0].size(); j++)
//			{
//				bool ret = IsOK(v4, v3, rows, cols, i, j);
//				if (ret == true)
//				{
//					str.push_back("YES");
//					goto s;
//				}
//			}
//		}
//		str.push_back("NO");
//	s:;
//	}
//	for (auto e : str)
//		cout << e << endl;
//	//system("pause");
//	return 0;
//}

void Swa(int x)
{
	
	printf("int Swa x:%d\n",x);
}
int main()
{
	int x = 0;
	Swa(x++);
	Swa(++x);
	system("pause");
	return 0;
}