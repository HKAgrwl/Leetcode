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
    
   bool checkSymmetric(TreeNode* lft,TreeNode* rgt){
        if(lft==NULL || rgt==NULL)
            return lft==rgt;
        if(lft->val!=rgt->val)
            return false;
        return (checkSymmetric(lft->left,rgt->right) && checkSymmetric(lft->right,rgt->left));
    }
    
    bool isSymmetric(TreeNode* root) {
       if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;
        if(checkSymmetric(root->left,root->right))
            return true;
        return false;
    }
};