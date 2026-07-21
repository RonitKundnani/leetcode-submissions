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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        int levelSize;
        while(!q.empty()){
            levelSize=q.size();
            vector<int> temp(levelSize);
            for(int i = 0; i < levelSize; i++){
                TreeNode* node=q.front();
                int f=node->val;
                q.pop();
                temp[i]=node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
