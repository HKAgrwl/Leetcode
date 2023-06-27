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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        if(root==NULL) return ans;
        while(!q.empty()){
            TreeNode* first = q.front();
            q.pop();    
            
            if(first==NULL){
                if(q.empty()) return ans;
                q.push(NULL);
                continue;
            }
            
            if(q.front()==NULL) ans.push_back(first->val);
            
            if(first->left) q.push(first->left);
            if(first->right) q.push(first->right);
        }
        
        return ans;
    }
};