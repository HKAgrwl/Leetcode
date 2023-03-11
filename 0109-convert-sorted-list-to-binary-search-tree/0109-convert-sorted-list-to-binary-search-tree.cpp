/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nodes;
        while(head!=NULL){
            nodes.push_back(head->val);
            head= head->next;
        }
        TreeNode* headNode = makeTree(nodes,0,nodes.size()-1);
        return headNode;
    }
    
    TreeNode* makeTree(vector<int> &nodes,int start,int end){
        if(start <= end){
            int mid = (start+end)/2;
            TreeNode* head = new TreeNode(nodes[mid]);
            head->left = makeTree(nodes,start,mid-1);
            head->right = makeTree(nodes,mid+1,end);
            return head;   
        }
        return NULL;
    }
};