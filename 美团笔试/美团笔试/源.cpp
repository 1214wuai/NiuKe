//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	vector<int> v;
//	//MPMPCPMCM DEFEGDE HINHKLIN
//	int i = 0;
//	while(i<s.size())
//	{
//		string tmp;
//		tmp += s[i];
//		for (int j = i + 1; j < s.size(); j++)
//		{
//			int pos = tmp.find(s[j]);
//			if (pos == -1)
//				tmp += s[j];
//			else
//				tmp.erase(pos, 1);
//			if (tmp.empty())
//			{
//				v.push_back(j - i+1);
//				i = j;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (i != v.size() - 1)
//			cout << v[i] << " ";
//		else
//			cout << v[i] << endl;;
//	}
//	return 0;
//}
////int main()
////{
////	string s;
////	getline(cin, s);
////	vector<string> v;
////	int pos = s.find(" ");
////	while (pos != -1)
////	{
////		pos = s.find(" ");
////		v.push_back(s.substr(0, pos));
////		s.erase(0, pos+1);
////	}
////	string ret = v[0];
////	int sz = ret.size();
////	int index = 0;
////	//ret+=v[0][0];
////	for (int i = 1; i < v.size(); i++)
////	{
////		int length = v[i].size();
////		for (int j = 0; j < length; j++)
////		{
////			if (index < sz)
////			{
////				//if (v[i][j] == ret[index])
////				//	index++;
////				//else if(ret.find(&v[i][j]))
////				if(ret.find(&v[i][j])!=-1)
////				{
////					//ret.insert(j+1, &v[i][j]);
////					index++;
////				}
////				else
////				{
////					ret.insert(j + 1, &v[i][j]);
////					index++;
////				}
////			}
////
////			
////		}
////	}
////	cout << ret << endl;
////	system("pause");
////	return 0;
////}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v = { 2,5,3,10,4 };
	vector<int> w = { 1,3,2,6,2 };
	int total = 12;
	int vsz = v.size();
	int wsz = w.size();

	vector<vector<int>> ret(vsz + 1, vector<int>(total + 1, 0));
	for (int i = 1; i <= vsz; i++)
	{
		for (int j = 1; j <= total; j++)
		{
			if (j >= w[i-1])
				ret[i][j] = max(ret[i - 1][j], (ret[i - 1][j - w[i-1]] + v[i-1]));
			else
				ret[i][j] = ret[i - 1][j];
		}
	}
	for (int i = 0; i <= vsz; i++)
	{
		for (int j = 0; j <= total; j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}