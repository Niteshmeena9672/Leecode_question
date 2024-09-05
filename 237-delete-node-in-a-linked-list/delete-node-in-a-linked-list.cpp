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
    /**
     * Deletes the node from the linked list, given only access to that node.
     * Note: This function does not delete the last node in the list.
     * @param node: Pointer to the node that needs to be deleted.
     */
    void deleteNode(ListNode* node) {
        // Copy the value from the next node into the current node
        node->val = node->next->val;
        
        // Update the current node's next pointer to skip the next node
        node->next = node->next->next;
        
        // Note: The original next node is not deleted explicitly here
        // The memory management for the original node is assumed to be handled elsewhere
    }
};
