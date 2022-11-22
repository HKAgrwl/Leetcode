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
    
vector<int> answer;
    
public:
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root);
        sort(answer.begin(),answer.end());
        return answer[k-1];
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return answer;
        }
        inorderTraversal(root->left);
        answer.push_back(root->val);
        inorderTraversal(root->right);
        return answer;
    }
};