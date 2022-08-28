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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        ListNode* interim = new ListNode(8);
        interim->next= head;
        head=interim;
        int size = getSize(head);
        int pos = size+1-n;
        ListNode* temp = head->next;
        ListNode* prev = head;
        int x=2;
        while(x<pos && temp!=NULL){
            temp=temp->next;
            prev=prev->next;
            x++;
        }
        prev->next = temp->next;
        head=head->next;
        return head;
        
    }
    
    int getSize(ListNode* head){
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL){
            temp=temp->next;
            i++;
        }
        return i;
    }
};