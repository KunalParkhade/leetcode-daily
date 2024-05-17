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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<TreeNode*> s;
        TreeNode* currentNode = root;
        TreeNode* lastRightNode=nullptr;
        
        while(!s.empty() || currentNode!=nullptr){
            while(currentNode!=nullptr){
                s.push(currentNode);
                currentNode = currentNode->left;
            }
            currentNode = s.top();

            if(currentNode->right!=lastRightNode && currentNode->right){
            currentNode=currentNode->right;
            continue;
        }

        s.pop();
        if(currentNode->left==nullptr && currentNode->right==nullptr && currentNode->val==target){
            if(s.empty()){
                return nullptr;
            }
            TreeNode* parent=s.top();
            if(parent->left==currentNode){
                parent->left=nullptr;
            }
            else{
                parent->right=nullptr;
            }
        }
        lastRightNode=currentNode;
        currentNode=nullptr;
        }
        return root;
    }
};