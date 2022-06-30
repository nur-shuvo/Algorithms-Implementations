class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> positionsOfChar[26];

        for (int i = 0; s[i]; i++) {
            positionsOfChar[s[i] - 'a'].push_back(i);
        }

        int cnt = 0;
        for (auto& word : words) {
            int xPos = -1;
            bool foundSubSequence = true;
            for (int i = 0; word[i]; i++) {
                auto it = upper_bound(positionsOfChar[word[i] - 'a'].begin(), positionsOfChar[word[i] - 'a'].end(), xPos);
                if (it == positionsOfChar[word[i] - 'a'].end()) {
                    foundSubSequence = false;
                    break;
                }
                xPos = *it;
            }
            if (foundSubSequence) cnt++;
        }
        return cnt;
    }
};