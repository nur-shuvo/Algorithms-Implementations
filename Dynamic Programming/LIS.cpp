class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), dp[n]; // LIS ending at dp[i]
        for (int i = 0; i < n; i++) dp[i] = 1;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++) ans = max(ans, dp[i]);

        // Find sequence
        int tmp = ans, next = 1e9;
        std::vector<int> lis;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == tmp && nums[i] < next) {
                lis.push_back(nums[i]);
                --tmp;
                next = nums[i];
            }
        }
        reverse(lis.begin(), lis.end());

        for (auto x : lis) cout << x << " ";

        return ans;
    }
};