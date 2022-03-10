// Monotonic stack
// Try to place char in non-descending order (lexicographical smallest)

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastIndex(26);
        for(int i = 0; i < s.size(); i++) {
            lastIndex[s[i]-'a'] = i;
        }

        stack<int>st;
        vector<bool>seen(26, false);

        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (seen[idx]) continue;

            while(!st.empty() and idx < st.top() and i < lastIndex[st.top()]) {
                int top = st.top();
                seen[top] = false;
                st.pop();
            }

            st.push(idx);
            seen[idx] = true;
        }

        string res = "";
        while (!st.empty()) {
            res += (char)(st.top() + 'a');
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
