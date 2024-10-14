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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftdepth = minDepth(root->left);
        int rightdepth = minDepth(root->right);
        if (leftdepth == 0 || rightdepth == 0)
            return max(leftdepth, rightdepth) + 1;
        return min(leftdepth, rightdepth) + 1;
    }
};
