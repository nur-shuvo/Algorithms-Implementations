/*

	if (j <= k)
		   dp[i-1][k] + points[i][j] - j + k
		 = (dp[i-1][k] + k) + (points[i][j] - j)

		if (j >= k)
		   dp[i-1][k] + points[i][j] + j - k
		 = (dp[i-1][k] - k) + (points[i][j] + j)

	We need leftMax (from left), rightMax(from right)

*/


class Solution {
public:
	long long maxPoints(vector<vector<int>>& points) {
		int n = points.size();
		int m = points[0].size();

		long long dp[n][m];
		//first row
		for (int j = 0; j < m; j++)
			dp[0][j] = points[0][j];

		for (int i = 1; i < n; i++) {

			long long leftMax[m];
			leftMax[0] = dp[i - 1][0] + 0;
			for (int k = 1; k < m; k++) {
				leftMax[k] = max(leftMax[k - 1], dp[i - 1][k] + k);
			}

			long long rightMax[m];
			rightMax[m - 1] = dp[i - 1][m - 1] - (m - 1);
			for (int k = m - 2; k >= 0; k--) {
				rightMax[k] = max(rightMax[k + 1], dp[i - 1][k] - k);
			}

			for (int j = 0; j < m; j++) {
				dp[i][j] = points[i][j] + max(leftMax[j] - j, rightMax[j] + j);
			}
		}

		long long ans = 0;
		for (int j = 0; j < m; j++)
			ans = max(ans, dp[n - 1][j]);

		return ans;
	}
};