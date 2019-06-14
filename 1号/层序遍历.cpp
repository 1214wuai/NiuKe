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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty())
        {
            if(q.front() != NULL)
            {
                v.push_back(q.front()->val);
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        return v;
    }
};
