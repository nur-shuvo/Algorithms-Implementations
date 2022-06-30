// use 4 directions , use a dp[i][j][4]
// dp[i][j][0] -> horizontal consecutive 1's at cell (i,j)
// dp[i][j][1] -> vertical consecutive 1's at cell (i,j)
// dp[i][j][2] -> diagonal consecutive 1's at cell (i,j)
// dp[i][j][0] -> anti-diagonal consecutive 1's at cell (i,j)

// if mat[i][j] == '1', then dp[i][j][0] = dp[i][j-1] + 1
// and so on

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int dp[m][n][4];
        int longestLineSize = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    //horizontal
                    if (j - 1 >= 0) dp[i][j][0] = dp[i][j - 1][0] + 1;
                    else dp[i][j][0] = 1;

                    //vertical
                    if (i - 1 >= 0) dp[i][j][1] = dp[i - 1][j][1] + 1;
                    else dp[i][j][1] = 1;

                    //diagonal
                    if (i - 1 >= 0 && j - 1 >= 0) dp[i][j][2] = dp[i - 1][j - 1][2] + 1;
                    else dp[i][j][2] = 1;

                    // anti-diagonal
                    if (i - 1 >= 0 && j + 1 < n) dp[i][j][3] = dp[i - 1][j + 1][3] + 1;
                    else dp[i][j][3] = 1;

                    longestLineSize = max(longestLineSize, max(max(dp[i][j][0], dp[i][j][1]), max(dp[i][j][2], dp[i][j][3])));
                }
                else {
                    dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0;
                }
            }
        }
        return longestLineSize;
    }
};