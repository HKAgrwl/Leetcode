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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val==0 && l2->val==0) return l1;
        ListNode* head1 = reverseList(l1);
        ListNode* head2 = reverseList(l2);
        
        ListNode* temp = new ListNode(-1);
        ListNode* fHead = temp;
        
        int rem = 0;
        int x = 0;
        
        while(head1 || head2){
            if(head1 && head2){
                x = head1->val + head2->val + rem;
                head1 = head1->next;
                head2 = head2->next;
            }else if(!head1){
                x = head2->val + rem;
                head2 = head2->next;
            }else{
                x = head1->val  + rem;
                head1 = head1->next;
            }

            temp->next = new ListNode(x%10);
            temp = temp->next; 
            rem = x/10;
        }
        fHead = reverseList(fHead);
        while(fHead->val==0) fHead = fHead->next;
        
        ListNode* foo = fHead;
        while(foo->next->val!=-1) foo = foo->next;
        foo->next = NULL;
        
        return fHead;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        head = pHead;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c;
        while(b){
            c = b->next;
            b->next = a;
            if(a==head) a->next = NULL;
            a = b;
            b = c;
        }
        
        return a;
    }
};