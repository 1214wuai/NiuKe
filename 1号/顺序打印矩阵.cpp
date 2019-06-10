class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> ret;
        int left = 0;
        int right = cols-1;
        int up = 0;
        int down = rows-1;
        while(left<=right && up<=down)
        {
            for(int i = left; i<=right; i++)//从左向右
                ret.push_back(matrix[up][i]);
            if(up<down)
                for(int i = up+1; i<=down; i++)//从上到下
                    ret.push_back(matrix[i][right]);
            if(up<down && left<right)
                for(int i = right-1; i>=left; i--)//从右到右
                    ret.push_back(matrix[down][i]);
            if(up+1<down && left<right)
                for(int i = down-1; i>=up+1; i--)//从下到上
                    ret.push_back(matrix[i][left]);
            up++;
            down--;
            left++;
            right--;
        }
        return ret;
    }
};
