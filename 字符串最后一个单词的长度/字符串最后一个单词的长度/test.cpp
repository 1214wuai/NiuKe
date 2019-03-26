#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int end = str.size() - 1;
		int count = 0;
		while (end >= 0 && str[end] != ' ')
		{
			++count;
			--end;
		}
		cout << count << endl;
		break;
	}

}