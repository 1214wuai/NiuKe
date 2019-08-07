/*
对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，
MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，
同时对于MaxTree的每棵子树，它的根的元素值为子树的最大值。
现有一建树方法，对于数组中的每个元素，其在树中的父亲为数组中它左边比它
大的第一个数和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，
那么它就是树根。请证明这个方法的正确性，同时设计O(n)的算法实现这个方法。
给定一个无重复元素的数组A和它的大小n，请返回一个数组，
其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，若为根则值为-1。
输入：[3,1,4,2],4
输出：[2,0,-1,2]
*/
class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        // write code here
        stack<int> s;
        vector<int> res;
        if(n<=0)
            return res;
        for(int i = 0; i<n; i++)
        {
            int pos = -1;
            while(!s.empty() && A[i]>A[s.top()])
            {
                int tmp = s.top();
                s.pop();
                if(res[tmp] == -1 || A[i]<A[res[tmp]])
                    res[tmp] = i;
            }
            if(!s.empty())
                pos=s.top();
            s.push(i);
            res.push_back(pos);
        }
        return res;
    }
};