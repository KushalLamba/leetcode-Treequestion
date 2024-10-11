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
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode*> pendingnodes;
        pendingnodes.push(root);
        bool past = false;
        while (!pendingnodes.empty()) {
            TreeNode* front = pendingnodes.front();
            pendingnodes.pop();
            if (front == NULL) {
                past = true;
            } else {
                if (past == true)
                    return false;
                pendingnodes.push(front->left);
                pendingnodes.push(front->right);
            }
        }
        return true;
    }
};