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
    vector<int> rightSideView(TreeNode *root) {
        // vector<int> ans;
        // if (!root)
        //     return ans;

        // queue<TreeNode*> q;
        // q.push(root);

        // while (!q.empty()) {
        //     int n = q.size();

        //     for (int i = 0; i < n; i++) {
        //         TreeNode* node = q.front();
        //         q.pop();

        //         if (i == n - 1) {
        //             ans.push_back(node->val);
        //         }

        //         if (node->left) {
        //             q.push(node->left);
        //         }

        //         if (node->right) {
        //             q.push(node->right);
        //         }
        //     }
        // }

        // return ans;
        vector<int> ans;
        if(!root) return ans;

        stack<pair<TreeNode *, int>> s;
        s.push({root, 0});

        while(!s.empty()){
            auto [node, level] = s.top();
            s.pop();

            if(level == ans.size()){
                ans.push_back(node->val);
            }

            if(node->left) s.push({node->left, level+1});
            if(node->right) s.push({node->right, level+1});
        }

        return ans;
    }
};