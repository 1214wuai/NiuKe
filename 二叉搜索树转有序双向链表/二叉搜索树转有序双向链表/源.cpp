/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

//ԭ��ָ�����ӽ���ָ�����Ϊ������ָ��ǰһ������ָ�룬ԭ��ָ�����ӽ���ָ�����Ϊ������ָ����һ������ָ�롣 
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