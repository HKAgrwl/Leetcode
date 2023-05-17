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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> storage;
        while(head){
            storage.push_back(head->val);
            head = head->next;
        }
        int left=0;
        int right = storage.size()-1;
        int sum = INT_MIN;
        while(left<right){
            int x = storage[left] + storage[right];
            if(x > sum) sum=x;
            left++;
            right--;
        }
        return sum;
    }
};