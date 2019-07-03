#include<iostream>
#include<vector>

using namespace std;

vector<int> a = { 1,1 };
void a_init()
{
	for (int i = 2; i<10005; i++)
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
}
int main()
{
	int n, t;
	a_init();
	while (cin >> n)
	{
		while (n--)
		{
			cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
}