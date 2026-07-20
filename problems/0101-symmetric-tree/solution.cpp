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
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr){return true;}
        return Ans(root->left,root->right);
    }

    bool Ans(TreeNode* p,TreeNode* q){
        if(p==nullptr and q==nullptr){return true;}
        if(p==nullptr or q==nullptr){return false;}
        if(p->val==q->val){return Ans(p->left,q->right) and Ans(p->right,q->left);}
        else{return false;}
    }
};
