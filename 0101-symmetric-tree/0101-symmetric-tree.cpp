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
    bool helper(TreeNode* leftv, TreeNode* rightv) {
        if (leftv == NULL && rightv == NULL)
            return true;
        if ((leftv == NULL && rightv != NULL) ||
            (rightv == NULL && leftv != NULL))
            return false;
        if (leftv->val != rightv->val)
            return false;
        if (helper(leftv->left, rightv->right) &&
            helper(leftv->right, rightv->left))
            return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* leftv = root;
        TreeNode* rightv = root;
        return helper(leftv, rightv);
    }
};