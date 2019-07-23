class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        stack<int> help;
        while(!numbers.empty())
        {
            int cur = numbers.back();
            numbers.pop_back();
            while(!help.empty() && help.top()>cur)
            {
                numbers.push_back(help.top());
                help.pop();
            }
            help.push(cur);
        }
        while(!help.empty())
        {
            numbers.push_back(help.top());
            help.pop();
        }
        return numbers;
    }
};