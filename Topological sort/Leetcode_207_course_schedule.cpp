class Solution {
public:
    // This problem turs into detecting cycle in a directed graph
    // Apply kahn's alogrithm
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses], indegree(numCourses, 0);
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

        if (bfsQue.size() == 0) return false;

        // RUN A BFS fashioned procedure

        while (!bfsQue.empty()) {
            int u = bfsQue.front();
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
            if (indegree[i] != 0) return false;
        }

        return true;
    }
};