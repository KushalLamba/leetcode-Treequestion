class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjlist;
        for (int i = 0; i < prerequisites.size(); i++) {
            adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adjlist[i].size(); j++) {
                int neighbour = adjlist[i][j];
                indegree[neighbour]++;
            }
        }
        int count = 0;
        queue<int> pendingnodes;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                count++;
                pendingnodes.push(i);
            }
        }
        while (!pendingnodes.empty()) {
            int front = pendingnodes.front();
            pendingnodes.pop();
            for (int i = 0; i < adjlist[front].size(); i++) {
                int neighbour = adjlist[front][i];
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    count++;
                    pendingnodes.push(neighbour);
                }
            }
        }
        if (count != V)
            return false;
        return true;
    }
};