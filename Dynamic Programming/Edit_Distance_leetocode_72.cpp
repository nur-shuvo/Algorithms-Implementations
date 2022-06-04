class Solution {
public:

    int solve(string word1, string word2, int n, int m, vector<vector<int>>& dp) {

        // If first string is empty, the only option is to
        // insert all characters of second string into first
        if (n == 0) {
            return m;
        }

        // If second string is empty, the only option is to
        // remove all characters of first string
        if (m == 0) {
            return n;
        }

        if (dp[n][m] != -1) return dp[n][m];

        if (word1[n - 1] == word2[m - 1]) { //match
            return dp[n][m] = solve(word1, word2, n - 1, m - 1, dp);
        }
        //unmatch
        return dp[n][m] = 1 + min(
            solve(word1, word2, n, m - 1, dp), //insert
            min(solve(word1, word2, n - 1, m, dp), //delete
                solve(word1, word2, n - 1, m - 1, dp)) //replace
        );
    }

    int minDistance(string word1, string word2) {
        int n, m;
        n = word1.size();
        m = word2.size();
        vector<vector<int>> dp((n + 1), vector<int>(m + 1, -1));
        return solve(word1, word2, n, m, dp);
    }
};