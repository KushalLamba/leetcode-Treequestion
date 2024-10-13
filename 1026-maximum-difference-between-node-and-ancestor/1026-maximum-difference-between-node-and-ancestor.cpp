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
    int maxAncestorDiff(TreeNode* root, int maxv = INT_MIN,
                        int minv = INT_MAX) {
        if (root == NULL)
            return maxv - minv;
        minv = min(minv, root->val);
        maxv = max(maxv, root->val);
        int leftdiff = maxAncestorDiff(root->left, maxv, minv);
        int rightdiff = maxAncestorDiff(root->right, maxv, minv);
        return max(leftdiff, rightdiff);
    }
};