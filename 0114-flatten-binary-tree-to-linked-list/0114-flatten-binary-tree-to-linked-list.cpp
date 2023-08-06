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
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        getPreorder(v,root);
        v.push_back(NULL);
        for(int i=0;i<v.size()-1;i++){
            v[i]->right = v[i+1];
            v[i]->left = NULL;
        }
    }
    
    void getPreorder(vector<TreeNode*> &v,TreeNode* root){
        if(root==NULL) return;
        v.push_back(root);
        if(root->left) getPreorder(v,root->left);
        if(root->right) getPreorder(v,root->right);
    }
};