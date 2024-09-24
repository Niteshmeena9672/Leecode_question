class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Check if the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return false; // No cycle in an empty or single-node list
        }

        // Initialize two pointers: slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        // Iterate until fast and slow meet
        do{
            // Check if fast has reached the end or its next node
            if (  fast == NULL || fast->next == NULL) {
                return false; // No cycle if fast reaches the end
            }

            // Advance slow and fast at different speeds
            slow = slow->next;
            fast = fast->next->next;
        }while (fast != slow);

        // If fast and slow meet, a cycle exists
        return true;
    }
};