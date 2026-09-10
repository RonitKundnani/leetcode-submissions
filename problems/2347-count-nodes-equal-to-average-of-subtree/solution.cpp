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
    vector<int> dfs(TreeNode *root){
        if(root==nullptr) return {0,0};
        auto left=dfs(root->left);
        auto right=dfs(root->right);
        int cnt=left[0]+right[0]+1;
        int sum=left[1]+right[1]+root->val;
        if(sum/cnt==root->val) ans++;
        return {cnt,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
