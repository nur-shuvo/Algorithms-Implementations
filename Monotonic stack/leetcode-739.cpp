class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>indexesStack;
        int n = temperatures.size();
        vector<int>ret(n, 0);
        for(int i = 0; i < temperatures.size(); i++) {
            int cur = temperatures[i];
            while(!indexesStack.empty() && temperatures[indexesStack.top()] < cur) {
                int topIndex = indexesStack.top();
                ret[topIndex] = i - topIndex;
                indexesStack.pop();
            }
            indexesStack.push(i);
        }
        return ret;
    }
};
