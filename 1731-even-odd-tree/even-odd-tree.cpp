class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root)
            return true;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<int> prevLevelValues;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevelValues;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Check if the node's value violates the Even-Odd property
                if ((level % 2 == 0 && (node->val % 2 == 0 || (i > 0 && node->val <= currLevelValues.back()))) ||
                    (level % 2 == 1 && (node->val % 2 == 1 || (i > 0 && node->val >= currLevelValues.back()))))
                    return false;
                
                currLevelValues.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            
            // Check if the current level values are strictly increasing or decreasing
            if (level % 2 == 0) {
                for (int i = 1; i < currLevelValues.size(); ++i) {
                    if (currLevelValues[i] <= currLevelValues[i - 1])
                        return false;
                }
            } else {
                for (int i = 1; i < currLevelValues.size(); ++i) {
                    if (currLevelValues[i] >= currLevelValues[i - 1])
                        return false;
                }
            }
            
            ++level;
        }
        
        return true;
    }
};