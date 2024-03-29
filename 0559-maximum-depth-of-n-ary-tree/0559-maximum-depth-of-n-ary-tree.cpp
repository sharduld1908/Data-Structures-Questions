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
    int maxDepth(Node* root) {
        if(root == nullptr) {
            return 0;
        }

        int max_depth = -1;
        for(int i = 0; i < root->children.size(); i++) {
            int curr_depth = maxDepth(root->children[i]);
            max_depth = max(curr_depth, max_depth);
        }

        if(max_depth == -1) {
            return 1;
        }
        return (max_depth + 1);
    }
};