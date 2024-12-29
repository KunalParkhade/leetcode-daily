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
    int max_diam = 0;

    int height(TreeNode* root) {
        if (!root)
            return 0;

        int lc_height = height(root->left);
        int rc_height = height(root->right);

        max_diam = max(max_diam, lc_height + rc_height);

        return 1 + max(lc_height, rc_height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int height_demo = height(root);

        return max_diam;
    }
};