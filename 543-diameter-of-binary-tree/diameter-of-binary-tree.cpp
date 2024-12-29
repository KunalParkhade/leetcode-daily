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
    int height(TreeNode* root) {
        if (!root)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int p_diam = height(root->left) + height(root->right);
        int l_diam = diameterOfBinaryTree(root->left);
        int r_diam = diameterOfBinaryTree(root->right);

        return max(p_diam, max(l_diam, r_diam));
    }
};