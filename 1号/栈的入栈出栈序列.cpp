class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int pushsize = pushV.size();
        int popsize = popV.size();
        if(pushsize != popsize)
            return false;
        stack<int> s;
        int k = 0;
        for(int i = 0; i<pushsize; i++)
        {
            if(pushV[i] != popV[k])
                s.push(pushV[i]);
            else
                k++;
        }
        while(!s.empty())
        {
            if(s.top() != popV[k])
                return false;
            s.pop();
            k++;
        }
        return true;
    }
};
