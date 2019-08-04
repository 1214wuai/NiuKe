/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

//原先指向左子结点的指针调整为链表中指向前一个结点的指针，原先指向右子结点的指针调整为链表中指向下一个结点的指针。 
class Solution {
public:
	void Convert1(TreeNode* cur, TreeNode*& pre)
	{
		if (!cur)
			return;
		Convert1(cur->left, pre);
		cur->left = pre;
		if (pre)
			pre->right = cur;
		pre = cur;
		//if(cur->right)
		Convert1(cur->right, pre);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		TreeNode* pre = NULL;

		Convert1(pRootOfTree, pre);
		TreeNode* ret = pRootOfTree;
		while (ret->left)
			ret = ret->left;
		return ret;
	}