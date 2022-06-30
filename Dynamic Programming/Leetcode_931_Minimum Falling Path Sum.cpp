/*

   dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1])

*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // base for the first row
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int res = INT_MAX;
                if (i - 1 >= 0) {
                    res = min(res, matrix[i][j] + dp[i - 1][j]);
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    res = min(res, matrix[i][j] + dp[i - 1][j - 1]);
                }
                if (i - 1 >= 0 && j + 1 < n) {
                    res = min(res, matrix[i][j] + dp[i - 1][j + 1]);
                }
                dp[i][j] = res;
            }
        }

        //min on the dp[n-1]
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};