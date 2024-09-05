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
    /**
     * Remove the nth node from the end of a singly linked list.
     * @param head: Pointer to the head of the linked list.
     * @param n: The position of the node to remove from the end (1-based index).
     * @return: The head of the modified linked list.
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create two pointers, both starting at the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Move the fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast pointer is null after moving n steps, 
        // it means we need to remove the head node
        if (fast == NULL) {
            // Remove the head node
            ListNode* newHead = head->next;
            delete head; // Free the memory of the old head node
            return newHead;
        }

        // Move both slow and fast pointers until fast reaches the end of the list
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow now points to the node before the one we want to remove
        ListNode* deletePtr = slow->next;
        slow->next = slow->next->next;

        // Delete the node to free memory
        deletePtr->next = NULL;
        delete(deletePtr);

        // Return the head of the modified list
        return head;
    }
};
