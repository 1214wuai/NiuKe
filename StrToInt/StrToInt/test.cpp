#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.size() == 0)
			return 0;
		int value = 0;
		int s = 0;
		if (str[0] == '-' ||
			str[0] == '+' ||
			(str[0] >= '0'&&str[0] <= '9'))
		{
			if (str[0] >= '0'&&str[0] <= '9')
				s = 0;
			else
				s = 1;
			for (size_t i = s; i<str.size(); i++)
			{
				if (str[i] >= '0'&&str[i] <= '9')
				{
					value = value * 10 + (str[i] - '0');
				}
				else
					return 0;
			}
			if (str[0] == '-')
				return -value;
			else
				return value;
		}
		return 0;
	}
};

int main()
{
	string s1("-123");
	Solution y;
	int x = y.StrToInt(s1);
	cout << x << endl;
	system("pause");
	return 0;
}