/*

if i < j
     values[i] + values[j] + i - j
   = (values[i] + i) + (values[j] - j)

Maimize (values[i] + i) to achieve max of this formula

*/


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), ans = -INT_MAX;

        int maxSoFar = values[0] + 0; // values[i] + i

        for (int j = 1; j < n; j++) {
            int cur = maxSoFar + values[j] - j;
            ans = max(ans, cur);
            maxSoFar = max(maxSoFar, values[j] + j);
        }
        return ans;
    }
};