/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //Recursive
        // if(root == nullptr || root->val == val) return root;

        // if(root->val < val) return searchBST(root->right, val);

        // return searchBST(root->left, val);

        //Iterative
        if(root == nullptr) return nullptr;

        while(root!=nullptr){
            if(root->val == val){
                return root;
            }
            else if(root->val < val){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return nullptr;
    }
};