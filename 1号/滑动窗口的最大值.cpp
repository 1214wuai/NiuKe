class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        int sz = num.size();
        if(sz-size<0 || size<0)
            return ret;
        deque<int> q;
        for(int i = 0; i<sz; i++)
        {
            while(!q.empty() && num[q.back()]<=num[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            if(q.front() == i-size)
                q.pop_front();
            if(i>=size-1)
            {
                ret.push_back(num[q.front()]);
            }
        }
        return ret;
    }
};