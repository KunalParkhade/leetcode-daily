/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // bool findpath(TreeNode* root, vector<TreeNode *> &path, TreeNode* data){
    //     if(root == nullptr) return false;

    //     path.push_back(root);

    //     if(root->val == data->val) return true;

    //     if(findpath(root->left, path, data)||findpath(root->right, path, data)) return true;

    //     path.pop_back();

    //     return false;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Optimized solution (Single Traversal)

        if(root == nullptr || root == p || root == q)   return root;

        TreeNode* left_lca = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_lca = lowestCommonAncestor(root->right, p, q);

        if(left_lca!=nullptr && right_lca!=nullptr)   return root;

        return (left_lca != nullptr) ? left_lca : right_lca;

        //Not Optimized
        // vector<TreeNode *> p1, p2;

        // if(!findpath(root, p1, p) || !findpath(root, p2, q)) return nullptr;

        // int i;

        // for(i = 0;i<p1.size() && i<p2.size();i++){
        //     if(p1[i]!=p2[i]){
        //         break;
        //     }
        // }

        // return p1[i-1];
    }
};