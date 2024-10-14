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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start,
                     int end, int& index) {
        if (start > end)
            return NULL;
        TreeNode* root = new TreeNode(postorder[index]);
        int i = start;
        for (; i <= end; i++) {
            if (postorder[index] == inorder[i])
                break;
        }
        index--;
        root->right = helper(inorder, postorder, i + 1, end, index);
        root->left = helper(inorder, postorder, start, i - 1, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int start = 0;
        int end = inorder.size() - 1;
        int index = end;
        return helper(inorder, postorder, start, end, index);
    }
};