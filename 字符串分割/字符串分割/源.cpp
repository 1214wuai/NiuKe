#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
bool wordBreak(string s, unordered_set<string> & dict)
{
	if (s.empty() || dict.empty())
		return false;
	int sz = s.size();
	vector<bool> can_break(sz + 1, false);
	//初始化 F(0)=true
	can_break[0] = true;
	//状态递推
	for (int i = 1; i <= sz; i++)
	{
		//F(i)= j<i && F(j) && substr(j+1,i)能在词典中找到
		for (int j = 0; j<i; j++)
		{
			if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end())
			{
				can_break[i] = true;
				break;
			}
		}
	}
	//返回结果
	return can_break[sz];
}
int main()
{
	string s = "leetcode";
	vector<string> dict_v = { "leet", "code" };
	unordered_set<string> dict(dict_v.begin(), dict_v.end());
	cout << wordBreak(s, dict) << endl;
	system("pause");
	return 0;
}