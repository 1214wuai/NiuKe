#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
void test()
{
	//char a[] = "abcdef";//自动接/0
	//char b[] = { 'a','b','c','d','e','f','\0' };//手动接/0
	//const char *c = "abcdef";
	//printf("%s\n", a);
	//printf("%s\n", b);
	//printf("%s\n", c);

	//printf("sizeof(a) = %d，7\n", sizeof(a));
	//printf("sizeof(b) = %d，7\n", sizeof(b));
	//printf("sizeof(c) = %d，4\n", sizeof(c));
	//printf("strlen(a) = %d，6\n", strlen(a));
	//printf("strlen(b) = %d，6\n", strlen(b));
	//printf("strlen(c) = %d，6\n", strlen(c));
	//float x = -2.3E-1;
	//int y = 2e5;
	//int z = 2e6;
	//printf("2e3 = %d\n", (int)(2e3));
	//printf("-2.3E-1 = %f\n", x);
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class A {
public:
	vector<int> v;
	void func()
	{
		v.push_back(1);
		func();
	}
		
};
ListNode* removeAll(ListNode* head, int value)
{
	ListNode* newList = new ListNode(-1);
	ListNode* cur = newList;
	while (head)
	{
		if (head->val != value)
		{
			cur->next = head;
			cur = cur->next;
		}
		head = head->next;
	}
	return newList->next;
}

void Sort(vector<int>& v, const int& sz)
{
	int j = 0;
	for (int i = 1; i<sz; i++)
	{
		int tmp = v[i];
		for (j = i; j>0 && v[j - 1]>tmp; j--)
			v[j] = v[j - 1];
		v[j] = tmp;
	}
}

bool VerifySquenceOfBST(vector<int> sequence) {
	int sz = sequence.size();
	if (sz<=0)
		return false;
	int root = sequence[sz - 1];
	vector<int> sequenceleft;
	int i = 0;
	for (i; i<sz-1; i++)
	{
		if (sequence[i]>root)
			break;
		sequenceleft.push_back(sequence[i]);
	}
	int j = i;
	vector<int> sequenceright;
	for (j; j<sz - 1; j++)
	{
		if (sequence[j]<root)
			return false;
		sequenceright.push_back(sequence[j]);
	}

	bool left = true;
	if (i>0)
		left = VerifySquenceOfBST(sequenceleft);
	bool right = true;
	if (i<sz - 1)
		right = VerifySquenceOfBST(sequenceright);
	if (left&&right)
		return true;
	else
		return false;
}

int main()
{
	//vector<int> v = { 1,3,2,5,7,6,4};
	//bool ret = VerifySquenceOfBST(v);
	//cout << ret << endl;
	A x;
	x.func();
	system("pause");
	return 0;
}