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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> pendingnodes;
        pendingnodes.push(root);
        pendingnodes.push(NULL);
        int maxsum = INT_MIN;
        int level = 0;
        int sum = 0;
        int currlevel = 1;
        while (!pendingnodes.empty()) {
            TreeNode* front = pendingnodes.front();
            pendingnodes.pop();
            if (front == NULL) {
                if (sum > maxsum) {
                    maxsum = sum;
                    level = currlevel;
                }
                sum = 0;
                if (!pendingnodes.empty()) {
                    currlevel++;
                    pendingnodes.push(NULL);
                }
            } else {
                if (front->left != NULL)
                    pendingnodes.push(front->left);
                if (front->right != NULL)
                    pendingnodes.push(front->right);
                sum += front->val;
            }
        }
        return level;
    }
};