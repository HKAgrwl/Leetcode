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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pHead = new ListNode(-1);
        pHead->next = head;
        ListNode* x = pHead;
        int k = right-left;
        while(left > 1){
            x = x->next;
            left--;
        }
        x->next = reverseList(x->next,k);
        return pHead->next;
    }
    
    ListNode* reverseList(ListNode* head,int k){
        if(head==NULL) return NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        while(k >=0 && temp){
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
            k--;
        }
        head->next = temp;
        return prev;
    }
};