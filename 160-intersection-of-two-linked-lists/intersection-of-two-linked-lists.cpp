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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Check if either list is empty, return null if so
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        // Initialize two pointers, one for each list
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        // Iterate until both pointers point to the same node
        while (temp1 != temp2) {
            // If temp1 reaches the end of list A, move it to the beginning of list B
            if (temp1 == NULL) {
                temp1 = headB;
            } else {
                temp1 = temp1->next;
            }

            // If temp2 reaches the end of list B, move it to the beginning of list A
            if (temp2 == NULL) {
                temp2 = headA;
            } else {
                temp2 = temp2->next;
            }
        }

        // If the pointers meet, they point to the intersection node
        return temp1;
    }
};