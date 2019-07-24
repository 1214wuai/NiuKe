class ReverseStack {
public:
    void reverse(vector<int>& stack, int top, int n)
    {
        int result = stack[n];
        if(n==top-1)
        {
            stack[0]=result;
            return;
        }
        else
        {
            reverse(stack,top,n+1);
            stack[top-n-1]=result;
        }
    }
    vector<int> reverseStackRecursively(vector<int> stack, int top) {
        // write code here
        if(stack.empty())
            return stack;
        reverse(stack,top,0);
        return stack;
    }
};