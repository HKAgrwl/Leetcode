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
    int sumNumbers(TreeNode* root) {
        int finalSum =0 ;
        helper(root,0,finalSum);
        return finalSum;
    }
    
    void helper(TreeNode* root,int sum,int &finalSum){
        sum = sum*10 + root->val; 
        if(!root->left && !root->right){
            cout<<sum<<endl;
            finalSum+=sum;
            return;
        }
        if(root->left) helper(root->left,sum,finalSum);
        if(root->right) helper(root->right,sum,finalSum);
    }
};