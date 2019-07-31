#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool ispathr(const vector<string>& v, const int rows, const int cols, int row, int col, const string s, int path, int& count, int sz)
{
	if (row < rows && col < cols)
	{
		if (v[row][col] == s[path])
		{
			if (path == sz - 1)
			{
				count++;
				return true;
			}
			else
				ispathr(v, rows, cols, row, ++col, s, ++path, count, sz);
		}
		else
			return false;
	}
	else
		return false;
}
bool ispathd(const vector<string>& v, const int rows, const int cols, int row, int col, const string s, int path, int& count, int sz)
{
	if (row < rows && col < cols)
	{
		if (v[row][col] == s[path])
		{
			if (path == sz - 1)
			{
				count++;
				return true;
			}
			else
				ispathd(v, rows, cols, ++row, col, s, ++path, count, sz);
		}
		else
			return false;
	}
	else
		return false;
}
bool ispathrd(const vector<string>& v, const int rows, const int cols, int row, int col, const string s, int path, int& count, int sz)
{
	if (row < rows && col < cols)
	{
		if (v[row][col] == s[path])
		{
			if (path == sz - 1)
			{
				count++;
				return true;
			}
			else
				ispathrd(v, rows, cols, ++row, ++col, s, ++path, count, sz);
		}
		else
			return false;
	}
	else
		return false;
}

void ispath(const vector<string>& v, const int rows, const int cols, int row, int col, const string s, int& path, int& count, int sz)
{
	if (path == sz - 1)
		return;
	if (v[row][col] == s[path])
	{
		ispathr(v, rows, cols, row, col + 1, s, path + 1, count, sz);
		ispathd(v, rows, cols, row + 1, col, s, path + 1, count, sz);
		ispathrd(v, rows, cols, row + 1, col + 1, s, path + 1, count, sz);
	}


}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> ret;
		while (n--)
		{
			int rows, cols;
			cin >> rows;
			cin >> cols;
			vector<string> v;
			v.resize(rows);
			for (int i = 0; i < rows; i++)
				cin >> v[i];
			string s;
			cin >> s;
			int sz = s.size();
			int path = 0;
			int count = 0;
			for (int row = 0; row < rows; row++)
			{
				for (int col = 0; col < cols; col++)
				{
					path = 0;
					ispath(v, rows, cols, row, col, s, path, count,sz);
				}
			}
			ret.push_back(count);
		}
		for (auto e : ret)
			cout << e << endl;
	}
	return 0;
}
