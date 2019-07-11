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
	//��ʼ�� F(0)=true
	can_break[0] = true;
	//״̬����
	for (int i = 1; i <= sz; i++)
	{
		//F(i)= j<i && F(j) && substr(j+1,i)���ڴʵ����ҵ�
		for (int j = 0; j<i; j++)
		{
			if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end())
			{
				can_break[i] = true;
				break;
			}
		}
	}
	//���ؽ��
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