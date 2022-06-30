class Solution {
public:
    int ans = -1, totalPeople, size[101], parent[101];

    void makeset(int x) {
        parent[x] = x;
        size[x] = 1;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void Union_by_size(int ts, int x, int y) {
        int r = find(x);
        int s = find(y);
        if (r == s) return;
        if (r != s) {
            if (size[r] < size[s])
                swap(r, s);
            parent[s] = r;
            size[r] += size[s];
            if (size[r] == totalPeople) { // all are in on group now
                ans = ts;
            }
        }
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        totalPeople = n;
        for (int i = 0; i < n; i++) {
            makeset(i);
        }
        sort(logs.begin(), logs.end());
        for (int i = 0; i < logs.size(); i++) {
            Union_by_size(logs[i][0], logs[i][1], logs[i][2]);
            if (ans != -1) return ans;
        }
        return -1;
    }
};