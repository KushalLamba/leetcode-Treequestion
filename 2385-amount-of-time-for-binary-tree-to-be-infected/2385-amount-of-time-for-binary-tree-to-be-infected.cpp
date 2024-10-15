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
    int helper(TreeNode* root, int start) {
        if (root == NULL)
            return 0;
        int leftcheck = helper(root->left, start);
        int rightcheck = helper(root->right, start);
        if (root->val == start) {
            maxdistance = max(leftcheck, rightcheck);
            return -1;
        }
        else if(leftcheck>=0 && rightcheck>=0)
        {
            return max(leftcheck,rightcheck)+1;
        }
        else
        {
            maxdistance=max(maxdistance,(abs(leftcheck)+abs(rightcheck)));
            return min(leftcheck,rightcheck)-1;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        helper(root, start);
        return maxdistance;
    }
};