//һ�������ǡ�õ������ĸ�����(�����������)�Ӻͣ��磺6 = 3 + 2 + 1�������Ϊ����������
//������֮�ʹ��ڸ����������Ϊ��ӯ������ ���2��60֮�����С��������͡�ӯ������
//���2��60֮�����С��������͡�ӯ����������������ʽ�����
//E : e1 e2 e3 ......(eiΪ����)
//G : g1 g2 g3 ......(giΪӯ��)
//����������֮��Ҫ�пո���β���ӿո�

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>e;
	vector<int>g;
	for (int n = 2; n <= 60; n++)
	{
		int sum = 0;
		for (int j = 1; j<n; j++)
		{
			if (n%j == 0)
				sum += j;
		}
		if (sum == n)
		{
			e.push_back(n);
		}
		if (sum > n)
		{
			g.push_back(n);
		}
	}
	cout << "E:";
	for (int i = 0; i < e.size(); i++)
	{
		cout << " " << e[i];
	}
	cout << endl;
	cout << "G:";
	for (int i = 0; i < g.size(); i++)
	{
		cout << " " << g[i];
	}
	return 0;
}