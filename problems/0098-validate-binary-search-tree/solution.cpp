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
    void inorder(TreeNode* root, vector<int>& vals) {
        if (root == nullptr) return;
        inorder(root->left, vals);   // left
        vals.push_back(root->val);   // node
        inorder(root->right, vals);  // right
    }

    bool isValidBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        for (int i = 1; i < (int)vals.size(); i++) {
            if (vals[i] <= vals[i-1]) return false;  
        }
        return true;
    }

};
