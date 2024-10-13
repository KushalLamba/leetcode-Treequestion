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
    int maxsum = INT_MIN;
    int helper(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftpath = helper(root->left);
        int rightpath = helper(root->right);
        int sum = 0;
        if (rightpath < 0 && leftpath < 0) {
            sum = root->val;
        } else {
            sum = root->val + max(leftpath, rightpath);
        }
        maxsum = max(maxsum, max(sum, root->val + leftpath + rightpath));
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxsum;
    }
};