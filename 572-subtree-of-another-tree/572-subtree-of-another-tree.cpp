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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        if(isIdentical(root,subRoot)) return true;
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
        
    }
    
    bool isIdentical(TreeNode* root,TreeNode* sroot){
        if(root==NULL && sroot==NULL) return true;
        if(root==NULL || sroot==NULL) return false;
        if(root->val==sroot->val){
            return(isIdentical(root->left,sroot->left) && isIdentical(root->right,sroot->right));
        }
        return false;
        
    }
};