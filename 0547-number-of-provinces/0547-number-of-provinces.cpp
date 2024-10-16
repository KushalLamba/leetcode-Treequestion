class Solution {
public:
    void dfs(int root, vector<vector<int>>& adj, vector<bool>& visited) {
        if (visited[root])
            return;
        visited[root] = true;
        for (int i = 0; i < adj[root].size(); i++) {
            if (!visited[adj[root][i]]) {
                dfs(adj[root][i], adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (i == j)
                    continue;
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }
        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};