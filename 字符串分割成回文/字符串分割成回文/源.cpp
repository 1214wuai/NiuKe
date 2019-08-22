//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//bool isPal(string s, int i, int j)
//{
//	while (i < j)
//	{
//		if (s[i] != s[j])
//			return false;
//		i++;
//		j--;
//	}
//	return true;
//}
////��̬�滮���ж�һ���ַ�������Ӵ��Ƿ�Ϊ���Ĵ�
//
//int MinOfCut(string & s)
//{
//	if (s.empty())
//		return -1;
//	int n = s.size();
//	vector<int> cut(n+1,0);
//	//��ʼ��  F[i] = i-1
//	for (int i = 0; i < n + 1; i++)
//		cut[i] = i - 1;
//	//����
//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			//j<i
//			//substr[j+1,i)�ǻ��Ĵ�
//			if (isPal(s, j, i - 1))
//			{
//				//F(i) = min(F(j)+1,F(i))
//				cut[i] = min(cut[j] + 1, cut[i]);
//			}
//		}
//	}
//	return cut[n];
//
//}
//int main()
//{
//	string s("ab");
//	cout << MinOfCut(s) << endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<bool>> is_PalDP(string s)
{
	int n = s.size();
	vector<vector<bool>> is_pal(n, vector<bool>(n, false));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (j == i)
				is_pal[i][j] = true;//F[i][i] = true   ��ʼ��
			else if (j == i + 1)//���������ַ�
				is_pal[i][j] = (s[i] == s[j]);
			else  //j>i+1
				is_pal[i][j] = (s[i] == s[j] && is_pal[i + 1][j - 1]);
		}
	}
	return is_pal;
}
int MinOfCut(string & s)
{
	if (s.empty())
		return -1;
	int n = s.size();
	vector<int> cut(n + 1, 0);
	//��ʼ��  F[i] = i-1
	for (int i = 0; i < n + 1; i++)
		cut[i] = i - 1;
	vector<vector<bool>> is_pal = is_PalDP(s);
	//����
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//j<i
			//substr[j+1,i)�ǻ��Ĵ�
			if (is_pal[j][i - 1])
			{
				//F(i) = min(F(j)+1,F(i))
				cut[i] = min(cut[j] + 1, cut[i]);
			}
		}
	}
	return cut[n];
}
int main()
{
	string s("acabaa");
	cout << MinOfCut(s) << endl;
	system("pause");
	return 0;
}
