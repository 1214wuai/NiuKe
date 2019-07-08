// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//vector<string> yuan;
//vector<string> xin;
//void yuanandxininit()
//{
//	for (int i = 0; i<5; i++)
//		yuan.push_back("V"+i);
//	for (int i = 0; i<21; i++)
//		yuan.push_back("A" + i);
//	for (int i = 0; i<26; i++)
//		xin.push_back("A" + i);
//}
const char* yuan = "VWXYZABCDEFGHIJKLMNOPQRSTU";
int main()
{
	string s1, s2;
	
	while (getline(cin, s1))
	{
		s2.clear();
		for (auto e : s1)
		{
			if (e >= 'A' && e <= 'Z')
			{
				s2 += yuan[e - 'A'];
			}
			else if (e == ' ')
				s2 += ' ';
			else
				return 0;
		}
		cout << s2 << endl;
	}
	return 0;
}