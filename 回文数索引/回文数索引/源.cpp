#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool IsSym(string s)
{
	string news = s;
	reverse(news.begin(), news.end());
	return news == s;
}

int main()
{
	int n;
	cin >> n;
	vector<int> ret;
	while (n--)
	{
		string s;
		cin >> s;
		if (IsSym(s))
		{
			ret.push_back(-1);
			goto x;
		}
		for (int i = 0; i<s.size(); i++)
		{
			string tmp = s;
			tmp = tmp.erase(i,1);
			if (IsSym(tmp))
			{
				ret.push_back(i);
				goto x;
			}
		}
	x:;
	}
	for (auto e : ret)
		cout << e << endl;
	system("pause");
	return 0;
}