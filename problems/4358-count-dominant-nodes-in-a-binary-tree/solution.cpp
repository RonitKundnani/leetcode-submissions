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
    int ans=0;
    int func(TreeNode* root){
        if(root==nullptr) return -1;
        int leftMax=func(root->left);
        int rightMax=func(root->right);
        int m=max(root->val,max(leftMax,rightMax));
        if(m==root->val) ans++;
        return m;
    }
    int countDominantNodes(TreeNode* root) {
        ans=0;
        func(root);
        return ans;
    }
};
