#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	vector<string> v;
	while (cin >> n)
	{
		v.resize(n);
		for (int i = 0; i<n; i++)
			cin >> v[i];
		for (int i = 0; i<n; i++)
		{
			if ((v[i][0] == '2' && v[i][1]>'3') || v[i][0] >= '3')
				v[i][0] == '0';
			if (v[i][3] >= '6')
				v[i][3] = '0';
			if (v[i][6] >= '6')
				v[i][6] = '0';

		}
		for (int i = 0; i<n; i++)
			cout << v[i] << endl;

	}
	return 0;
}