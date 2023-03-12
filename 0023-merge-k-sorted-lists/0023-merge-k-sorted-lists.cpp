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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* interim = new ListNode(INT_MIN);
        helper(lists,0,n,interim);
        return interim->next;
        
    }
    
    void helper(vector<ListNode*>& lists,int i,int n,ListNode* prevHead){
        if(i>=n){
            return;
        }
        ListNode* head1 = prevHead;
        ListNode* head2 = lists[i];
        if(head2==NULL){
            helper(lists,i+1,n,head1);
            return;
        }
        ListNode* head= NULL;
        if(head1->val > head2->val){
            head = head2;
            head2=head2->next;
        }else{
            head = head1;
            head1=head1->next;
        }
        ListNode* temp = head;
        
        
        while(head1!=NULL && head2!=NULL){
            if(head1->val > head2->val){
                temp->next = head2;
                temp=temp->next;
                head2=head2->next;
            }else{
                temp->next= head1;
                temp = temp->next;
                head1=head1->next;
            }
        }
        
        while(head1!=NULL){
            temp->next=head1;
            head1=head1->next;
            temp=temp->next;
        }
        while(head2!=NULL){
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
        }
        
        helper(lists,i+1,n,head);
        
    }
};