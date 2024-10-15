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
    vector<int> helper(TreeNode* root) {
        if (root == NULL)
            return {0, 0};
        vector<int> leftans = helper(root->left);
        vector<int> rightans = helper(root->right);
        int first = leftans[0] + rightans[0] + root->val;
        int second = leftans[1] + rightans[1] + 1;
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