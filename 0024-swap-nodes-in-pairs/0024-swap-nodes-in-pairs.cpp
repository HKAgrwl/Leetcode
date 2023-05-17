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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        
        ListNode* proxyHead = new ListNode(0);
        proxyHead->next=head;
        head = proxyHead;
        
        ListNode* a = head->next;
        ListNode* b = head->next->next;
        
        while(true){
            a->next = b->next;
            b->next=a;
            proxyHead->next = b;
            if(a->next && a->next->next){
                proxyHead = a;
                a = a->next;
                b = a->next;
                continue;
            }
            return head->next;
            
        }
        return head->next;
    }
};