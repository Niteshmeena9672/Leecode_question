/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;

        // First loop: Detect cycle by moving slow and fast pointers
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected, now find the start of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start of the cycle
            }
        }

        // If no cycle is detected, return NULL
        return NULL;
    }
};
