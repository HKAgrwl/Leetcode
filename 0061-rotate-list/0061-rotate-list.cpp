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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int count = 0;
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        count++;
        temp->next = head;
        temp = head;
        k = k%count;
        k = count-k;
        while(k>1){
            temp= temp->next;
            k--;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};