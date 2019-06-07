class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int sz = sequence.size();
        if(sz<1)
            return false;
        int root = sequence[sz-1];
        vector<int> sequenceleft;
        int i = 0;
        for(i; i<sz-1; i++)
        {
            if(sequence[i]>root)
                break;
            sequenceleft.push_back(sequence[i]);
        }
        int j = i;
        vector<int> sequenceright;
        for(j; j<sz-1; j++)
        {
            if(sequence[j]<root)
                return false;
            sequenceright.push_back(sequence[j]);
        }
        
        bool left = true;
        if(i>0)
            left=VerifySquenceOfBST(sequenceleft);
        bool right = true;
        if(i<sz-1)
            right=VerifySquenceOfBST(sequenceright);
        if(left&&right)
            return true;
        else
            return false;
    }
};
