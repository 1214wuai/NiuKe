class Solution {
public:
    void push(int value) {
        s1.push(value);
        if(Min.empty() || Min.top() >= value)
            Min.push(value);
    }
    void pop() {
        if(!s1.empty())
        {
            if(Min.top()==s1.top())
                Min.pop();
            s1.pop();
        }

    }
    int top() {
        return s1.top();
    }
    int min() {
        return Min.top();
    }
private:
    stack<int> s1;
    stack<int> Min;
};
