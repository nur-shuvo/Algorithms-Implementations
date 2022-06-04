/* Returns length of Longest common substring for X[0..m-1], Y[0..n-1] */
void lcSubstring(char* X, char* Y, int m, int n)
{
    int L[m + 1][n + 1];

    int ans = 0;

    /* Following steps build L[m+1][n+1] in bottom up
      fashion. Note that L[i][j] = longest common substring ending at positio i and j
      */
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                ans = max(ans, L[i][j]);
            }
            else
                L[i][j] = 0;
        }
    }
    return ans;
}