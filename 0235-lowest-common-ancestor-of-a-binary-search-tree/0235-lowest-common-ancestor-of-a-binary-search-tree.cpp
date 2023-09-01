/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca = NULL;
    unordered_map<TreeNode*,bool> m;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!p || !q) return NULL;
        dfs(root,p,q);
        return lca;
    }
    
    bool dfs(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return false;
        if(m[root]) return false;
        m[root] = true;
        bool check = false;
        if(root == p || root==q) check = true;
        bool left = dfs(root->left,p,q);
        bool right = dfs(root->right,p,q);
        if((left && right) || (check && (left||right))){
            lca = root;
            return true;
        }
        if(check || left || right) return true;
        return false;
    }
};