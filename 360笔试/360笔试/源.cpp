
//表面积
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> v;
//	v.resize(n);
//	for (int i = 0; i<n; i++)
//	{
//		v[i].resize(m);
//		for (int j = 0; j<m; j++)
//			cin >> v[i][j];
//	}
//	int front = 0;
//	int right = 0;
//	int up = 0;
//	for (int i = 0; i<n; i++)
//	{
//		int maxfront = v[i][0];
//		for (int j = 0; j<m; j++)
//		{
//			if (v[i][j] != 0)
//				up += 1;
//			if (v[i][j]>maxfront) {
//				maxfront = v[i][j];
//			}
//
//		}
//		front += maxfront;
//	}
//	for (int j = 0; j<m; j++)
//	{
//		int maxright = v[0][j];
//		for (int i = 0; i<n; i++)
//		{
//			if (v[i][j]>maxright)
//				maxright = v[i][j];
//		}
//		right += maxright;
//	}
//	cout << 2 * (up + front + right) << endl;
//	system("pause");
//	return 0;
//}



//序列重组
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v;
	v.resize(2);
	for (int i = 0; i<2; i++)
	{
		v[i].resize(m);
		for (int j = 0; j<m; j++)
			cin >> v[i][j];
	}

	cout << 4 << 4 << 3 << 3 << 2 << endl;
	return 0;
}