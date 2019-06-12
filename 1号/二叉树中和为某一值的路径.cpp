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
    vector<vector<int>> ret;
    vector<int> tmp;
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL)
            return ret;
        tmp.push_back(root->val);
        if((root->val)-expectNumber == 0 && root->left==NULL && root->right==NULL)
            ret.push_back(tmp);
        FindPath(root->left,expectNumber-(root->val));
        FindPath(root->right,expectNumber-(root->val));
        if(tmp.size()!=0)
            tmp.pop_back();
        return ret;
    }
};
