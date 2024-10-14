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
    int maxlenght = 0;
    void answer(TreeNode* root, bool left, int length) {
        if (root == NULL)
            return;
        maxlenght = max(maxlenght, length);
        if (left) {
            answer(root->left, false, length + 1);
            answer(root->right, true, 1);
        } else {
            answer(root->left, false, 1);
            answer(root->right, true, length + 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        answer(root, true, 0);
        answer(root, false, 0);
        return maxlenght;
    }
};
