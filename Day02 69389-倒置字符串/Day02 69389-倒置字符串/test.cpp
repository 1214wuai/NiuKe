//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	// 翻转整个句子
	reverse(s.begin(), s.end());  
	// 翻转单词    
	auto start = s.begin();
	while (start != s.end())
	{        
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	return 0;
	// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出 
	//string s1, s2;
	//cin >> s2;
	//while (cin >> s1)
	//	s2 = s1 + " " + s2;
	//cout << s2 << endl;
	//return 0;
}
