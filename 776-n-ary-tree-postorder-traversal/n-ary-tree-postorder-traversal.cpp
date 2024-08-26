/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postorderHelper(Node* currNode, vector<int>& postOrderList) {
        if (currNode == nullptr)
            return;

        for (Node* childNode : currNode->children) {
            postorderHelper(childNode, postOrderList);
        }

        postOrderList.push_back(currNode->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr)
            return result;

        // postorderHelper(root, result);
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* currNode = st.top();
            st.pop();

            result.push_back(currNode->val);

            for (Node* child : currNode->children)
                st.push(child);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};