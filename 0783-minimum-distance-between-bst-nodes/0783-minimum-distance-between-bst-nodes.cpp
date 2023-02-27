class Solution {
public:
    int minDistance = INT_MAX;
    // Initially, it will be null.
    TreeNode* prevValue;
        
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);

        // Find the difference with the previous value if it is there.
        if (prevValue != NULL) {
            minDistance = min(minDistance, root->val - prevValue->val);
        }
        prevValue = root;
        
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        
        return minDistance;
    }
};