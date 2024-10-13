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
    vector<TreeNode*> ans;
    unordered_map<string, int> mp;
    string helper(TreeNode* root) {
        if (root == NULL)
            return "N";
        string s = to_string(root->val) + "," + helper(root->left) + "," +
                   helper(root->right);
        if (mp.count(s) > 0 && mp[s] == 1)
            ans.push_back(root);
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return ans;
    }
};