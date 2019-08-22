//#include<iostream>
//#include<vector>
//using namespace std;
//int FindX(const vector<int>& v, const int& x, const int left, int right, const int& sz)
//{
//	if (left > right || left<0 ||  right >=sz )
//		return -1;
//	int mid = left + (right - left) / 2;
//	if (v[mid] == x)
//		return mid;
//	else if (v[mid] < x)
//		FindX(v, x, mid+1, right,sz);
//	else
//		FindX(v, x, left, mid-1,sz);
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		if (n<0)
//			return 0;
//		vector<int> v;
//		v.resize(n);
//		for (int i = 0; i<n; i++)
//			cin >> v[i];
//		int x;
//		cin >> x;
//		int ret = FindX(v, x, 0, n-1, n);
//		cout << ret << endl;
//	}
//
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n>0)
		{
			int ret = 1;
			while (n >= 5)
			{
				ret *= 3;
				n -= 3;
			}
			ret *= n;
			cout << ret << endl;
		}
	}


	return 0;
}