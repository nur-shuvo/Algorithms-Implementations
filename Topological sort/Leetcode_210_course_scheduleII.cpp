class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses], ans, indegree(numCourses, 0);
        int pn = prerequisites.size();

        for (int i = 0; i < pn; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> bfsQue;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                bfsQue.push(i);
            }
        }

        if (bfsQue.size() == 0) return {};

        // RUN A BFS fashioned procedure

        while (!bfsQue.empty()) {
            int u = bfsQue.front();
            ans.push_back(u);
            bfsQue.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                indegree[v]--;
                if (indegree[v] == 0) {
                    bfsQue.push(v);
                }
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] != 0) return {};
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};