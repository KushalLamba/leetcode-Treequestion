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
    int maxvalue = 0;
    int helper(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftvalue = helper(root->left);
        int rightvalue = helper(root->right);
        maxvalue = max(maxvalue, leftvalue + rightvalue);
        return max(leftvalue, rightvalue) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxvalue;
    }
};