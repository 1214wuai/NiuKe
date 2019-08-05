#include<iostream>
#include<string>
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
	string s;
	cin >> s;
	int sz = s.size();
	if (IsSym(s))
	{
		cout << sz << endl;
		return 0;
	}
	for (int i = 0; i<sz; i++)
	{
		string news = s;
		string tmp = s.substr(0, i);
		reverse(tmp.begin(), tmp.end());
		news += tmp;
		if (IsSym(news))
		{
			cout << news.size() << endl;
			break;
		}
	}
	return 0;
}