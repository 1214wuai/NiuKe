/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)
            return true;
        else if(pRoot1==NULL)
            return false;
        else if(pRoot1->val != pRoot2->val)
            return false;
        else
            return IsSubtree(pRoot1->left,pRoot2->left) && IsSubtree(pRoot1->right,pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        bool result = false;
        if(pRoot1->val == pRoot2->val)
            result = IsSubtree(pRoot1,pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->left,pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->right,pRoot2);
        return result;
    }
};