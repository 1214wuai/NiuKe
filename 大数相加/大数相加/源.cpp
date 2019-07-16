#include<iostream>
#include<string>
#include<vector>

using namespace std;
string GetNumberWithFu(string &s1, string &s2)//s1是负数，s2是正数
{
	string ret;
	int sz1 = s1.size();
	int sz2 = s2.size();

	bool flag = true;//默认正数大
	if (sz1 > sz2 + 1)
		flag = false;//负数大
	else if (sz1 = sz2 + 1)//二数一样长
	{
		for (int i = 0; i < sz2; i++)
		{
			if (s1[i + 1] > s2[i])
			{
				flag = false;
				break;//负数大
			}
		}
	}
	int la = sz1 > (sz2 + 1) ? (sz1 - 1) : sz2;
	vector<int> num1(la, 0);
	vector<int> num2(la, 0);
	int j = 0;
	for (int i = sz1 - 1; i > 0; i--)
		num1[j++] = s1[i] - '0';
	j = 0;
	for (int i = sz2 - 1; i >= 0; i--)
		num2[j++] = s2[i] - '0';
	if (flag)//正数大
	{
		for (int i = 0; i < la; i++)
		{
			num2[i] = num2[i] - num1[i];
			if (num2[i] < 0)
			{
				num2[i] += 10;
				num2[i + 1] --;
			}
		}
		int i = la-1;
		while (num2[i] == 0)
		{
			i--;
			if (i == -1)
				return "0";
		}

		for (i; i >= 0; i--)
			ret.push_back('0' + num2[i]);
		return ret;
	}
	else//负数大
	{
		for (int i = 0; i < la; i++)
		{
			num1[i] = num1[i] - num2[i];
			if (num1[i] < 0)
			{
				num1[i] += 10;
				num1[i + 1] --;
			}
		}
		int i = la-1;
		while (num1[i] == 0)
		{
			i--;
			if (i == -1)
				return "0";
		}
		ret.push_back('-');
		for (i; i >= 0; i--)
			ret.push_back('0' + num1[i]);
		return ret;
	}

}

string GetNumber(string &s1, string &s2)//两个正数or负数
{
	string ret;
	if (s1.empty())
		return s2;
	if (s2.empty())
		return s1;
	if (s1.size() < s2.size())//字符串较长的是s1
	{
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	int sz1 = s1.size();
	int sz2 = s2.size();
	vector<int> num1(sz1+1, 0);
	vector<int> num2(sz1+1, 0);

	int j = 0;
	for (int i = sz1 - 1; i >= 0; i--)
		num1[j++] = s1[i] - '0';
	j = 0;
	for (int i = sz2 - 1; i >= 0; i--)
		num2[j++] = s2[i] - '0';
	int carry = 0;
	
	for (int i = 0; i < sz1+1; i++)
	{
		num1[i] = num1[i]+num2[i]+carry;
		if (num1[i] > 9)
		{
			num1[i] = num1[i] - 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	int i = sz1;
	while(num1[i] == 0)
		i--;
	for (i; i >= 0; i--)
		ret.push_back('0' + num1[i]);
	return ret;

}
string GetNumber2(string &s1, string &s2)//main函数调用的函数
{
	string ret;
	if (s1.empty())
		return s2;
	if (s2.empty())
		return s1;
	bool flag1 = true, flag2 = true;//默认两个数都是正数
	if (s1[0] == '-')
		flag1 = false;
	if (s2[0] == '-')
		flag2 = false;
	if (flag1&&flag2)
		return GetNumber(s1, s2);//两个数都是正数
	else if (!flag1&&flag2)
		return GetNumberWithFu(s1,s2);//s1为负数
	else if(flag1&&!flag2)
		return GetNumberWithFu(s2, s1);//s2为负数
	else
	{
		//两个都是负数
		string ret;
		ret.push_back('-');
		string s3 = s1.substr(1, s1.size() - 1);
		string s4 = s2.substr(1, s2.size() - 1);
		ret += GetNumber(s3, s4);
		return ret;
	}

}


int main()
{
	while (1)
	{
		string s1;
		string s2;
		getline(cin, s1);
		getline(cin, s2);
		//string ret = GetNumber(s1, s2);
		//cout <<s1<<" + "<< s2<<" = "<< ret << endl;
		string ret2 = GetNumber2(s1, s2);
		cout << s1 << " + " << s2 << " = " << ret2 << endl;
	}
}