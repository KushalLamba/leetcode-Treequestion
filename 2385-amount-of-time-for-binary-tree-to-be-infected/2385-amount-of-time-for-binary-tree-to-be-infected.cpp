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
    int maxdistance = 0;
    pair<bool, int> helper(TreeNode* root, int start) {
        if (root == NULL)
            return {false, 0};
        pair<bool, int> leftcheck = helper(root->left, start);
        pair<bool, int> rightcheck = helper(root->right, start);
        if (root->val == start) {
            maxdistance = max(leftcheck.second, rightcheck.second);
            return {true, 1};
        } else if (leftcheck.first == true) {
            maxdistance =
                max(maxdistance, leftcheck.second + rightcheck.second);
            return {true, leftcheck.second + 1};
        } else if (rightcheck.first == true) {
            maxdistance =
                max(maxdistance, leftcheck.second + rightcheck.second );
            return {true, rightcheck.second + 1};
        } else {
            return {false, max(leftcheck.second, rightcheck.second) + 1};
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        helper(root, start);
        return maxdistance;
    }
};