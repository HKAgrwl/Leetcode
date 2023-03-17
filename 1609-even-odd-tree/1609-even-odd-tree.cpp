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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int flag=-1;
        while(!q.empty()){
            TreeNode* node = q.front();
            // if(node) cout<<node->val<<endl;
            q.pop();
            
            if(node==NULL){
                if(q.empty()) return true;
                q.push(NULL);
                flag*=-1;
                continue;
            }
            
            if(flag==1){
                if((node->val)%2!=0) return false;
                if(q.front()){
                    if(q.front()->val >= node->val) return false;
                }
            }
            
            if(flag==-1){
                if((node->val)%2==0) return false;
                if(q.front()){
                    if(q.front()->val <= node->val) return false;
                }
            }
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return true;
    }
};