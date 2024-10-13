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
    vector<vector<int>> ans;
    void helper(TreeNode* root, int targetSum, vector<int> output, int sum) {
        if (root == NULL) {
            return;
        }
        sum += root->val;
        output.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == sum)
                ans.push_back(output);
            return;
        }
        helper(root->left, targetSum, output, sum);
        helper(root->right, targetSum, output, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> output;
        helper(root, targetSum, output, 0);
        return ans;
    }
};