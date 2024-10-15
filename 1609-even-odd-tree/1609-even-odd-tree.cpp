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
    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode*> pendingnodes;
        pendingnodes.push(root);
        pendingnodes.push(NULL);
        int level = 0;
        int maxvalue = INT_MIN;
        int minvalue = INT_MAX;
        while (!pendingnodes.empty()) {
            TreeNode* front = pendingnodes.front();
            pendingnodes.pop();
            if (front == NULL) {
                level++;
                maxvalue = INT_MIN;
                minvalue = INT_MAX;
                if (!pendingnodes.empty())
                    pendingnodes.push(NULL);
            } else {
                if (level % 2 == 0) {
                    if ((front->val) % 2 == 0)
                        return false;
                    if (maxvalue >= front->val)
                        return false;
                    maxvalue = front->val;
                } else {
                    if ((front->val) % 2 != 0)
                        return false;
                    if (minvalue <= front->val)
                        return false;
                    minvalue = front->val;
                }
                if (front->left != NULL)
                    pendingnodes.push(front->left);
                if (front->right != NULL)
                    pendingnodes.push(front->right);
            }
        }
        return true;
    }
};