//// write your code here cpp
//#include<iostream>
//#include<vector>
//#include<math.h>
//using namespace std;
//int main()
//{
//	int a;
//	while (cin >> a)
//	{
//		vector<int> v;
//		for (int i = 2; i<sqrt(a); i++)
//		{
//			if (a%i == 0)
//			{
//				while (a%i==0)
//				{
//					a = a / i;
//				}
//			}
//			v.push_back(a);
//		}
//		cout << a << " =";
//		for (int i = 0; i<v.size() - 1; i++)
//		{
//			cout << " " << v[i] << " *";
//		}
//		cout << " " << v[v.size() - 1] << endl;
//	}
//	return 0;
//}
#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, k, i;
	while (cin >> n)
	{
		k = 0;
		for (i = 2; i <= sqrt(n); i++)
		{ 
			if ((n % i) == 0)
			{
				while ((n % i) == 0)
				{
					n = n / i;
				}
				k++;
			}
		}
		if (n != 1)
			k++;
		cout << k << endl;
	}
	return 0;
}