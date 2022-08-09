/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        while(!pendingNodes.empty()){
            Node* x = pendingNodes.front();
            pendingNodes.pop();
            if(x!=NULL){
                x->next = pendingNodes.front();
            }
            if(x==NULL && pendingNodes.empty()){
                return root;
            }
            if(x==NULL){
                pendingNodes.push(NULL);
            }else{
                if(x->left){
                    pendingNodes.push(x->left);
                }
                if(x->right){
                    pendingNodes.push(x->right);
                }
            }
        }
        return root;
    }
};