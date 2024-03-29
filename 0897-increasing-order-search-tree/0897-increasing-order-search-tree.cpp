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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* prev = dummy;

        inorderTraversal(root, prev);

        return dummy->right;
    }

    void inorderTraversal(TreeNode* root, TreeNode*& prev) {
        if(root == nullptr) {
            return;
        }
        
        inorderTraversal(root->left,prev);

        root->left = nullptr;
        prev->right = root;
        prev = root;

        inorderTraversal(root->right,prev);
    }
};