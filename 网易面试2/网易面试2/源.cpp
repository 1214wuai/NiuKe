//#include<iostream>
//#include<vector>
//#include<stack>
//using namespace std;
//bool Find(const vector<int>& v,const int &count)
//{
//	int sz = v.size();
//	for (int i = 0; i < sz; i++)
//	{
//		if (v[i] == count)
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	int T;
//	while (cin >> T)
//	{
//		
//		while (T--)
//		{
//			int n;
//			cin >> n;
//			vector<int> v;
//			v.resize(n);
//			for (int i = 0; i<n; i++)
//				cin >> v[i];
//			vector<int> NumOfOne;
//
//			for (int i = 0; i<n; i++)
//			{
//				int x = v[i];
//				int count = 0;
//				while (x>0)
//				{
//					x = x & (x - 1);
//					count++;
//				}
//
//				if (!Find(NumOfOne, count))
//					NumOfOne.push_back(count);
//			}
//			cout << NumOfOne.size() << endl;
//		}
//		
//	}
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	vector<int> ret;
	while (T--)
	{
		vector<int> v;
		v.resize(6);
		for (int i = 0; i < 6; i++)
			cin >> v[i];
		int m = v[0];
		int t = v[1];
		int m1 = v[2];
		int t1 = v[3];
		int m2 = v[4];
		int t2 = v[5];
		int count = 0;
		int In = 1;
		int Out = 1;
		while (t > 0)
		{
			if (In > 0)
				count += m1;
			if (Out > 0)
				count -= m2;
			if (count < 0)
				count = 0;
			t--;
			if (In <= t1)
				In++;
			if (In == t1 + 1)
				In = 1 - t1;
			if (Out <= t2)
				Out++;
			if (Out == t2 + 1)
				Out = 1 - t2;
		}
		if (count >= v[0])
			ret.push_back(v[0]);
		else if (count >= 0)
			ret.push_back(count);
		else
			ret.push_back(0);
	}
	for (auto e : ret)
		cout << e << endl;
	system("pause");
	return 0;
}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int T;
//	cin >> T;
//	vector<int> ret;
//	while (T--)
//	{
//		vector<int> v;
//		v.resize(6);
//		for (int i = 0; i<6; i++)
//			cin >> v[i];
//		int count = 0;
//		int t = v[1];
//		int t1 = v[3];
//		while (t > 0)
//		{
//			if (t > 2 * t1)
//			{
//				while (t > 2 * t1)
//				{
//					t -= 2 * t1;
//					count += v[2] * t1;
//				}
//			}
//			else if (t > t1)
//			{
//				count += v[2] * t1;
//				break;
//			}
//			else
//			{
//				count += v[2] * v[1];
//				break;
//			}
//		}
//		t = v[1];
//		int t2 = v[5];
//		while (t > 0)
//		{
//			if (t > 2 * t2)
//			{
//				while (t > 2 * t2)
//				{
//					t -= 2 * t2;
//					count -= v[4] * t2;
//				}
//			}
//			else if (t > t2)
//			{
//				count -= v[4] * t2;
//				break;
//			}
//			else
//			{
//				count -= v[4] * v[1];
//				break;
//			}
//		}
//
//		if (count >= v[0])
//			ret.push_back(v[0]);
//		else if (count >= 0)
//			ret.push_back(count);
//		else
//			ret.push_back(0);
//	}
//	for (auto e : ret)
//		cout << e << endl;
//	//system("pause");
//	return 0;
//}

//3
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int Find( string& str)
//{
//	//F[i]前i个字符最大长度
//	//F[i] = 
//	int sz = str.size();
//	vector<int> v(sz, 0);
//	vector<int> modify;
//	//int count = 0;
//	v[0] = 1;
//	for (int i = 1; i < sz; i++)
//	{
//		if (str[i] == str[i - 1])
//			v[i] = v[i - 1] + 1;
//		else
//		{
//			if (modify.size() < 2)
//			{
//				modify.push_back(i);
//				str[i] = str[i - 1];
//				v[i] = v[i - 1] + 1;
//			}
//			else
//			{
//				modify.clear();
//				v[i] = max(v[i - 1], 1);
//			}
//		}
//	}
//	return v.back();
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (int i = 0; i<n; i++)
//		cin >> v[i];
//	vector<int> ret;
//	for (int i = 0; i<n; i++)
//	{
//		string str = v[i];
//		int sz = Find(str);
//		ret.push_back(sz);
//	}
//	for (auto e : ret)
//		cout << e << endl;
//	//system("pause");
//	return 0;
//}


//4 洪水
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> v[i];
//	int k;
//	cin >> k;
//	vector<int> q;
//	q.resize(k);
//	for (int i = 0; i < k; i++)
//		cin >> q[i];
//
//	vector<int> ret;
//	for (int i = 0; i < k; i++)
//	{
//		int count = 0;
//		int sz = v.size();
//		if (sz > 3)
//		{
//			//for (int j = 1; j < sz - 2; j++)
//			//{
//			//	if (v[j] > q[i] && v[j-1] < q[i] && v[j+1]<q[i])
//			//		count++;
//			//}
//			for (int j = 0; j < sz; j++)
//			{
//				if (v[j] > q[i])
//				{
//					while (j<sz && v[j] > q[i])
//					{
//						j++;
//					}
//					count++;
//				}
//			}
//			ret.push_back(count);
//		}
//	}
//	for (auto e : ret)
//		cout << e << endl;
//	//system("pause");
//	return 0;
//}