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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* itr = head;
        int n = 0;
        while(itr != NULL){
            n++;
            itr = itr->next;
        }
        k = k%n;
        if(k==0){
            return head;
        }
        itr = head;
        ListNode* slow = head;
        while(k != 0){
            itr = itr->next;
            k--;
        }
        while(itr->next != NULL){
            itr = itr->next;
            slow = slow->next;
        }
        ListNode* a = slow->next;
        slow->next = NULL;
        itr->next = head;
        return a;
    }
};