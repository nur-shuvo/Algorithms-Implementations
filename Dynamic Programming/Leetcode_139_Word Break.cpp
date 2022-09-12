class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), start = 0;
        unordered_map<string, bool> isPresentWord;

        for (auto& x : wordDict) {
            isPresentWord[x] = true;
        }

        vector<bool> dp(n, false); // dp[i] = if it is possible for[0...i]

        string str = "";
        for (int i = 0; i < n; i++) {
            str += s[i];
            if (isPresentWord.find(str) != isPresentWord.end()) {
                dp[i] = true;
                start = i;
                break;
            }
        }

        for (int i = start + 1; i < n; i++) {
            /*
               Two cases: 1. [0...i] is present in list
                          2. [0...i] is not present
            */
            if (isPresentWord.find(s.substr(0, i + 1)) != isPresentWord.end()) {
                dp[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (dp[j] and isPresentWord.find(s.substr(j + 1, i - j)) != isPresentWord.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};