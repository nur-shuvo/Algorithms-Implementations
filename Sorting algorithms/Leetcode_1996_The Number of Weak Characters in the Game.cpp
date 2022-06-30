class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int len = properties.size(), cnt = 0;
        sort(properties.begin(), properties.end());

        vector<int> maxFromRightToIndex(len);
        int mxSoFar = -1;
        for (int i = len - 1; i >= 0; i--) {
            mxSoFar = max(properties[i][1], mxSoFar);
            maxFromRightToIndex[i] = mxSoFar;
        }

        vector<vector<int>> ::iterator it = properties.begin();
        while (it != properties.end()) {
            vector<int> search = { (*it)[0] + 1, -INT_MAX };
            auto searchIt = lower_bound(it, properties.end(), search);
            if (searchIt != properties.end()) { // if found
                int index = searchIt - properties.begin();
                if (maxFromRightToIndex[index] > (*it)[1]) {
                    cnt++;
                }
            }
            it++;
        }

        return cnt;
    }
};