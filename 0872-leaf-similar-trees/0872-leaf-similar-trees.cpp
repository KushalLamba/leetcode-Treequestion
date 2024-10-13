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
    void leaffinder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->val);
        }
        leaffinder(root->left, ans);
        leaffinder(root->right, ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first;
        vector<int> second;
        leaffinder(root1, first);
        leaffinder(root2, second);
        if (first == second)
            return true;
        return false;
    }
};