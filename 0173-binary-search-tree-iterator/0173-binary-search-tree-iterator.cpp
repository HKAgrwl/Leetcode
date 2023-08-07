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
class BSTIterator {
public:
    vector<TreeNode*> v;
    int count = 0;
    
    int i;
    void getLevelOrder(TreeNode* root){
        if(root==NULL) return;
        getLevelOrder(root->left);
        v.push_back(root);
        count++;
        getLevelOrder(root->right);
        
    }
    
    BSTIterator(TreeNode* root) {
        i=-1;
        getLevelOrder(root);
    }
    
    int next() {
        i++;
        return v[i]->val;
    }
    
    bool hasNext() {
        return (i < count-1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */