class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {
        unordered_map<int, vector<int>> adjlist;
        unordered_map<int, int> childtoparent;
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                adjlist[i].push_back(leftChild[i]);
                if (childtoparent.find(leftChild[i]) != childtoparent.end())
                    return false;
                childtoparent[leftChild[i]] = i;
            }
            if (rightChild[i] != -1) {
                adjlist[i].push_back(rightChild[i]);
                if (childtoparent.find(rightChild[i]) != childtoparent.end())
                    return false;
                childtoparent[rightChild[i]] = i;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (childtoparent.find(i) == childtoparent.end()) {
                if (root != -1)
                    return false;
                root = i;
            }
        }
        if(root==-1) return false;
        queue<int> pendingnodes;
        pendingnodes.push(root);
        vector<bool> visited(n, false);
        visited[root] = true;
        int count = 1;
        while (!pendingnodes.empty()) {
            int front = pendingnodes.front();
            pendingnodes.pop();
            for (int i = 0; i < adjlist[front].size(); i++) {
                if (visited[adjlist[front][i]])
                    return false;
                pendingnodes.push(adjlist[front][i]);
                visited[adjlist[front][i]] = true;
                count++;
            }
        }
        return count == n;
    }
};