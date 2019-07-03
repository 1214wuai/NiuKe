
// Definition for singly-linked list.
#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int>s1, s2;
		while (l1 != NULL)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}
		int a = 0, b = 0;
		while (!s1.empty())
		{
			a = a * 10 + s1.top();
			s1.pop();
		}
		while (!s2.empty())
		{
			b = b * 10 + s2.top();
			s2.pop();
		}
		int c = a + b;
		int d = c % 10;
		ListNode ret(d);
		ListNode cur = ret;
		c /= 10;
		while (c != 0)
		{
			d = c % 10;
			c /= 10;
			ListNode x(d);
			cur.next = &x;
			cur = *(cur.next);
		}
		return &ret;
	}
};