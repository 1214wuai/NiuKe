#include<iostream>
#include<vector>
#include<string>
using namespace std;

int Find(vector<int> v, int x)
{
	for (auto e : v)
	{
		if (e == x)
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	vector<int> v1;
	vector<vector<int>> v2;
	vector<vector<int>> v3;
	while (cin >> n)
	{
		v1.resize(n);
		v2.resize(n);
		v3.resize(n);
		for (int i = 0; i<n; i++)
		{
			cin >> v1[i];
			v2[i].resize(v1[i]);
			for (int j = 0; j<v1[i]; j++)
				cin >> v2[i][j];
		}
		for (int i = 0; i<n; i++)
		{
			v3[i].clear();
			int sz = v2[i].size();
			for (int j = sz - 1; j >= 0; j--)
			{
				if (Find(v3[i],v2[i][j]))
					v3[i].push_back(v2[i][j]);
			}
			int sz1 = v3[i].size();
			for (int j = 0; j<sz1; j++)
				cout << v3[i][j] << " ";
			cout << endl;
		}

	}
	return 0;
}