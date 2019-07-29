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
			//输出最小值
			cout << minstack.top() << endl;
		}
		else if (op == 1)
		{
			//入栈
			int x;
			cin >> x;
			datestack.push(x);
			if (minstack.empty() || minstack.top() >= x)
				minstack.push(x);
		}
		else
		{
			//出栈，并输出出栈的值
			cout << datestack.top() << endl;
			if (datestack.top() == minstack.top())
				minstack.pop();
			datestack.pop();
		}
	}
	return 0;
}