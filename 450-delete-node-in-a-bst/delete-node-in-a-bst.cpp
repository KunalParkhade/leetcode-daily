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
    TreeNode* inorderSuccessor(TreeNode* curr){
        curr = curr->right;

        while(curr!=nullptr && curr->left!=nullptr){
            curr=curr->left;
        }

        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;

        if (key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* successor = inorderSuccessor(root);
                root->val=successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};