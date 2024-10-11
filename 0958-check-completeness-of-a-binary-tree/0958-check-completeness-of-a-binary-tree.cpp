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
    int countnode(TreeNode* root) {
        if (root == NULL)
            return 0;
        return countnode(root->left) + countnode(root->right) + 1;
    }
    bool helper(TreeNode* root, int index, int& nodecount) {
        if (root == NULL)
            return true;
        if (index > nodecount)
            return false;
        bool left = helper(root->left, 2 * index, nodecount);
        bool right = helper(root->right, 2 * index + 1, nodecount);
        return left && right;
    }
    bool isCompleteTree(TreeNode* root) {
        int index = 1;
        int nodecount = countnode(root);
        return helper(root, index, nodecount);
    }
};