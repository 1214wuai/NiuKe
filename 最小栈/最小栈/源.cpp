#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	stack<int> datestack;
	stack<int> minstack;
	int n;
	cin >> n;
	while (n--)
	{
		int op;
		cin >> op;
		if (op == 0)
		{
			//�����Сֵ
			cout << minstack.top() << endl;
		}
		else if (op == 1)
		{
			//��ջ
			int x;
			cin >> x;
			datestack.push(x);
			if (minstack.empty() || minstack.top() >= x)
				minstack.push(x);
		}
		else
		{
			//��ջ���������ջ��ֵ
			cout << datestack.top() << endl;
			if (datestack.top() == minstack.top())
				minstack.pop();
			datestack.pop();
		}
	}
	return 0;
}