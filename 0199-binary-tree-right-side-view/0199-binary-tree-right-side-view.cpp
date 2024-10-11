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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> values;
        if (root == NULL)
            return values;
        queue<TreeNode*> pendingnodes;
        pendingnodes.push(root);
        pendingnodes.push(NULL);
        TreeNode* prev = root;
        while (!pendingnodes.empty()) {
            TreeNode* front = pendingnodes.front();
            pendingnodes.pop();
            if (front == NULL) {
                values.push_back(prev->val);
                if (!pendingnodes.empty()) {
                    pendingnodes.push(NULL);
                }
            } else {
                if (front->left != NULL) {
                    pendingnodes.push(front->left);
                }
                if (front->right != NULL) {
                    pendingnodes.push(front->right);
                }
            }
            prev = front;
        }
        return values;
    }
};