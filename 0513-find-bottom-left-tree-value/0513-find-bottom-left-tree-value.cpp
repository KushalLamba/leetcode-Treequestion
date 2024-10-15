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
    int maxdepth = -1;
    int result = 0;
    void dfs(TreeNode* root, int depth) {
        if (root == NULL)
            return;
        if (depth > maxdepth) {
            maxdepth = depth;
            result = root->val;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};