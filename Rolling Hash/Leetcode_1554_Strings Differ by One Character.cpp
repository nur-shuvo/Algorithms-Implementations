const int p = 31;
const long long mod = 1e9 + 7;

class Solution {
public:

    bool checkCandidates(string str1, string str2, int j) {
        int cnt = 0;
        for (int i = 0; str1[i]; i++) {
            if (str1[i] != str2[i]) {
                cnt++;
            }
        }
        return (cnt == 1 && str1[j] != str2[j]);
    }

    bool differByOne(vector<string>& dict) {
        int n = dict.size(), m = dict[0].size();
        vector<long long> p_pow(m);
        p_pow[0] = 1;

        for (int i = 1; i < m; i++)
            p_pow[i] = (p_pow[i - 1] * p) % mod;

        vector<long long> hash(n, 0); // hash of ith string in dict
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hash[i] = (hash[i] + (p_pow[j] * (dict[i][j] - 'a' + 1)) % mod) % mod;
            }
        }

        unordered_map<long long, vector<int>> isHashPresent; // hash to posititons

        long long h, temp_h;
        for (int i = 0; i < n; i++) {
            h = hash[i];
            for (int j = 0; j < m; j++) {
                // jth char delete, and compute hash
                temp_h = (h - (p_pow[j] * (dict[i][j] - 'a' + 1) % mod) + mod) % mod;
                if (isHashPresent.find(temp_h) != isHashPresent.end()) {
                    for (int k = 0; k < isHashPresent[temp_h].size(); k++)
                        if (checkCandidates(dict[i], dict[isHashPresent[temp_h][k]], j))
                            return true;
                }
                isHashPresent[temp_h].push_back(i);
            }
        }

        return false;
    }
};