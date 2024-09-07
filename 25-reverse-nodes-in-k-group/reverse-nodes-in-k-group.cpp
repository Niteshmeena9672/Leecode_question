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
     * Function to reverse the entire linked list.
     * @param head: Pointer to the head of the linked list.
     * @return New head of the reversed linked list.
     */
    ListNode* reverseLinkedList(ListNode *head) {
        ListNode* temp = head;  // Initialize current node to head
        ListNode* prev = NULL;  // Initialize previous node to NULL
        
        // Traverse through the list and reverse the links
        while(temp != NULL) {
            ListNode* front = temp->next;  // Store next node
            temp->next = prev;             // Reverse the current node's pointer
            prev = temp;                   // Move 'prev' one step forward
            temp = front;                  // Move 'temp' one step forward
        }
        return prev;  // Return the new head of the reversed list
    }

    /**
     * Function to get the k-th node from the current position in the list.
     * @param temp: Current node pointer.
     * @param k: Position to move to from the current node.
     * @return Pointer to the k-th node or NULL if it doesn't exist.
     */
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;  // Since we are starting from the current node, reduce k by 1
        while(temp != NULL && k > 0) {
            k--;
            temp = temp->next;  // Move to the next node
        }
        return temp;  // Return the k-th node or NULL
    }

    /**
     * Function to reverse every k nodes in the linked list.
     * @param head: Pointer to the head of the linked list.
     * @param k: Number of nodes to reverse in each group.
     * @return The new head of the modified linked list.
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;      // Initialize temp to the head of the list
        ListNode* prevLast = NULL;  // Pointer to the last node of the previous reversed group
        
        // Iterate through the list and reverse k nodes at a time
        while(temp != NULL) {
            ListNode* kThNode = getKthNode(temp, k);  // Get the k-th node

            // If less than k nodes remain, no reversal is done
            if(kThNode == NULL) {
                if(prevLast) {
                    prevLast->next = temp;  // Connect the last processed node
                }
                break;  // Break the loop as no more reversals are needed
            }
            
            ListNode* nextNode = kThNode->next;  // Store the next node after k-th
            kThNode->next = NULL;  // Temporarily break the list
            
            // Reverse the current k-group
            reverseLinkedList(temp);

            // If this is the first group, update the head to the new head
            if(temp == head) {
                head = kThNode;
            } else {
                prevLast->next = kThNode;  // Connect the last group to the new reversed group
            }
            
            prevLast = temp;  // Move prevLast to the current group
            temp = nextNode;  // Move temp to the next part of the list to continue the process
        }
        
        return head;  // Return the new head of the list
    }
};
