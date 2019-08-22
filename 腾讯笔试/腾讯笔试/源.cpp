#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n < 1)
			return 0;
		vector<int> v1(n);
		vector<int> v2(n);
		for (int i = 0; i < n; i++)
			cin >> v1[i];
		for (int i = 0; i < n; i++)
			cin >> v2[i];
		vector<int> v3(n, 0);// 0休息  1工作  2健身
		for (int i = 0; i < n; i++)
		{
			if (v1[i] == 0 && v2[i] == 0)
				;
			else if (v1[i] == 1 && v2[i] == 0)
			{
				if (i > 0 && v3[i - 1] == 1)
					;
				else
					v3[i] = 1;
			}
			else if (v1[i] == 0 && v2[i] == 1)
			{
				if (i > 0 && v3[i - 1] == 2)
					;
				else
					v3[i] = 2;
			}
			else if (v1[i] == 1 && v2[i] == 1)
			{
				if (i > 0 && v3[i - 1] == 1)
					v3[i] = 2;
				else if (i > 0 && v3[i - 2] == 2)
					v3[i] = 1;
				else
					v3[3] = 2;
			}
		}
		int count = 0;
		for (auto e : v3)
		{
			if (e == 0)
				count++;
		}
		cout << count;
	}
	return 0;
}

//4.
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> v1;
//		if (n < 1)
//			return 0;
//		vector<int> v;
//		v.resize(n);
//		for (int i = 0; i < n; i++)
//			cin >> v[i];
//		for (int i = 0; i < n; i++)
//		{
//			int count = 1;
//			int m = v[i];
//			int j = 0;
//			if (i > 0)
//			{
//				int max = v[i - 1];
//				for (j = i - 1; j >= 0; j--)
//				{
//					if (v[j] >= max)
//					{
//						max = v[j];
//						count++;
//					}
//				}
//			}
//			if (i < n - 1)
//			{
//				int max = v[i + 1];
//				for (j = i + 1; j < n; j++)
//				{
//					if (v[j] >= max)
//					{
//						max = v[j];
//						count++;
//					}
//				}
//			}
//
//			v1.push_back(count);
//		}
//		for (int i = 0; i<v1.size(); i++)
//		{
//			cout << v1[i];
//			if (i != v1.size() - 1)
//				cout << " ";
//		}
//	}
//	return 0;
//}



//3.
//int main()
//{
//	int n, L;
//	cin >> n >> L;
//	if (n < 1 || L < 1)
//		return 0;
//	vector<vector<int>> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		v[i].resize(2);
//		cin >> v[i][0] >> v[i][1];
//	}
//
//}


//2.
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		if (n < 1)
//			return 0;
//		int count = 1;
//		while (n--)
//		{
//			count *= 2;
//		}
//		vector<int> v1(count);
//		for (int i = 0; i < count; i++)
//			cin >> v1[i];
//		int m;
//		if (m < 0)
//			return 0;
//		vector<int> v2(m);
//		for (int i = 0; i < m; i++)
//			cin >> v2[i];
//		vector<int> v3;
//		//.....
//		for (auto e : v3)
//			cout << e << endl;
//	}
//	return 0;
//}

//1.
//void FindStr(const string& s1, string& s2, vector<int>& v,int pos, int sz)
//{
//	if (pos == sz)
//		return;
//	if (s1[pos] == '[')
//	{
//		v.push_back(s1[pos + 1] - '0');
//		for (int i = 0; i < (s1[pos + 1] - '0'); i++)
//		{
//			FindStr(s1, s2, v, pos + 3, sz);
//		}
//	}
//	else if (s1[pos] == ']')
//	{
//		//FindStr(s1, s2, v, pos + 1, sz);
//		return;
//	}
//	else
//	{
//		s2 += s1[pos];
//		FindStr(s1, s2, v, pos + 1, sz);
//	}
//
//}
//int main()
//{
//	string s1;
//	while (cin >> s1)
//	{
//		//HG[3|B[2|CA]]F
//		stack<string> st;
//		vector<int> v;
//		string s2,s3;
//		FindStr(s1, s2, v,0,s1.size());
//		for (int i = s1.size() - 1; i >= 0; i--)
//		{
//			if (s1[i] != ']')
//				s3 += s1[i];
//			else
//				break;
//		}
//		if (s3.size() != s1.size())
//		{
//			for (int i = s3.size() - 1; i >= 0; i--)
//				s2 += s3[i];
//		}
//	
//		cout << s2 << endl;
//		//system("pause");
//		
//	}
//	return 0;
//}