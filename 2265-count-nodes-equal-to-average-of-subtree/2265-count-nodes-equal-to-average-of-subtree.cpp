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
    int countindex = 0;
    pair<int, int> helper(TreeNode* root) {
        if (root == NULL)
            return {0, 0};
        pair<int, int> leftans = helper(root->left);
        pair<int, int> rightans = helper(root->right);
        int first = leftans.first + rightans.first + root->val;
        int second = leftans.second + rightans.second + 1;
        int average = first / second;
        if (average == root->val)
            countindex++;
        return {first, second};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return countindex;
    }
};