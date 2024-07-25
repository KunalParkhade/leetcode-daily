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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //Recursive
        // if(root == nullptr){
        //     return new TreeNode(val);
        // }
        // else if(root->val < val){
        //     root->right = insertIntoBST(root->right, val);
        // }
        // else{
        //     root->left = insertIntoBST(root->left, val);
        // }

        // return root;

        //Iterative
        TreeNode* newnode = new TreeNode(val);
        if(root == nullptr) return newnode;

        TreeNode* current = root;
        TreeNode* parent = nullptr;

        //This is for finding the parent
        while(current!=nullptr){
            parent = current;
            if(val < current->val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }

        if(val < parent->val){
            parent->left = newnode;
        }
        else{
            parent->right = newnode;
        }

        return root;
    }
};