/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> pendingnodes;
        pendingnodes.push(root);
        pendingnodes.push(NULL);
        int maxvalue = INT_MIN;
        while (!pendingnodes.empty()) {
            TreeNode* front = pendingnodes.front();
            pendingnodes.pop();
            if (front == NULL) {
                ans.push_back(maxvalue);
                maxvalue = INT_MIN;
                if (!pendingnodes.empty())
                    pendingnodes.push(NULL);
            } else {
                if (front->left != NULL)
                    pendingnodes.push(front->left);
                if (front->right != NULL)
                    pendingnodes.push(front->right);
                maxvalue = max(maxvalue, front->val);
            }
        }
        return ans;
    }
};