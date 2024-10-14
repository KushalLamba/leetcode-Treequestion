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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        deque<pair<TreeNode*, long long>> pendingnodes;
        pendingnodes.push_back(make_pair(root, 0));
        int maxlength = 0;

        while (!pendingnodes.empty()) {
            long long minIndex = pendingnodes.front().second;
            maxlength =
                max(maxlength, static_cast<int>(pendingnodes.back().second -
                                                minIndex + 1));
            int size1 = pendingnodes.size();
            while (size1 > 0) {
                TreeNode* front = pendingnodes.front().first;
                long long index = pendingnodes.front().second -
                                  minIndex; // Normalize the index
                pendingnodes.pop_front();
                if (front->left != NULL) {
                    pendingnodes.push_back(
                        make_pair(front->left, 2 * index + 1));
                }
                if (front->right != NULL) {
                    pendingnodes.push_back(
                        make_pair(front->right, 2 * index + 2));
                }
                size1--;
            }
        }
        return maxlength;
    }
};