/*
  Like merge process in merge sort. ... ...
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            // Let's check if A[i] intersects B[j].
            // lo - the startpoint of the intersection
            // hi - the endpoint of the intersection
            int lo = max(firstList[i][0], secondList[j][0]);
            int hi = min(firstList[i][1], secondList[j][1]);
            if (lo <= hi) {
                ans.push_back({ lo, hi });
            }
            // Remove the interval with the smallest endpoint
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};