#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		bool flag = 1;
		int Ha[26] = { 0 };
		for (size_t i = 0; i<s.size(); ++i)
		{
			++Ha[s[i] - 'a'];
		}
		for (size_t i = 0; i<s.size(); ++i)
		{
			if (Ha[s[i] - 'a'] == 1)
			{
				cout << s[i] << endl;
				flag = 0;
				break;
			}
				
		}
		if(flag)
			cout << 0 << endl;
	}
	return 0;
}