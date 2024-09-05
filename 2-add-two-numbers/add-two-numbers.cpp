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
     * Add two numbers represented by linked lists, where each node contains a single digit.
     * The digits are stored in reverse order, with the least significant digit at the head.
     * @param l1: Pointer to the head of the first linked list.
     * @param l2: Pointer to the head of the second linked list.
     * @return: Pointer to the head of the new linked list representing the sum.
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to serve as the starting point of the result list
        ListNode* ans = new ListNode();
        ListNode* temp = ans; // Temporary pointer to track the head of the result list
        int carry = 0; // Initialize carry to 0
        
        // Traverse both linked lists and process until both lists and carry are exhausted
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = 0; // Initialize sum for this digit
            
            // Add value from the first list if available
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next; // Move to the next node in the first list
            }
            
            // Add value from the second list if available
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next; // Move to the next node in the second list
            }
            
            // Include any carry from the previous iteration
            sum += carry;
            
            // Update carry for the next iteration
            carry = sum / 10;
            
            // Create a new node with the digit value (sum % 10) and append to the result list
            ListNode* node = new ListNode(sum % 10);
            ans->next = node;
            ans = ans->next; // Move to the newly added node
        }
        
        // Return the result list, starting from the first valid node (skipping the dummy node)
        return temp->next;
    }
};
