int dir1[] = { 1, -1, 0 , 0 };
int dir2[] = { 0, 0, 1 , -1 };

class Solution {
public:

    bool visited[101][101], canReached;

    void canReach(int i, int j, int n, int m, vector<vector<int>>& heights, int diff) {
        visited[i][j] = true;

        if (i == n - 1 && j == m - 1) {
            canReached = true;
            return;
        }

        for (int idx = 0; idx < 4; idx++) {
            int ii = i + dir1[idx];
            int jj = j + dir2[idx];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
                if (visited[ii][jj] == false && abs(heights[ii][jj] - heights[i][j]) <= diff) {
                    canReach(ii, jj, n, m, heights, diff);
                }
            }
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int lo = 0, hi = 1000000, ans;
        while (lo <= hi) {
            memset(visited, false, sizeof(visited));
            canReached = false;
            int mid = lo + (hi - lo) / 2;
            canReach(0, 0, n, m, heights, mid);
            if (canReached) {
                hi = mid - 1;
                ans = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};