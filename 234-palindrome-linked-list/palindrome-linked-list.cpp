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
    // Function to reverse a linked list
    ListNode* reverseLinkedList(ListNode* head) {
        // Initialize 'temp' at the head of the linked list
        ListNode* temp = head;  
   
        // Initialize pointer 'prev' to NULL, representing the previous node
        ListNode* prev = NULL;  
   
        // Traverse the list, continue until 'temp' reaches the end (NULL)      
        while(temp != NULL) {  
            // Store the next node in 'front' to preserve the reference
            ListNode* front = temp->next;  
       
            // Reverse the direction of the current node's 'next' pointer
            // to point to 'prev'
            temp->next = prev;  
       
            // Move 'prev' to the current node for the next iteration
            prev = temp;  
       
            // Move 'temp' to the 'front' node, advancing the traversal
            temp = front; 
        }
   
        // Return the new head of the reversed linked list
        return prev;
    }

    // Function to find the middle node of the linked list
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers, slow and fast, to find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
    
        // Traverse the linked list to find the middle using slow and fast pointers
        while (fast->next != NULL && fast->next->next != NULL) {
            // Move the slow pointer one step at a time
            slow = slow->next;  
        
            // Move the fast pointer two steps at a time
            fast = fast->next->next;  
        }
        // Return the slow pointer, which will be at the middle node
        return slow;
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        // Find the middle node of the list
        ListNode* middleNodePos = middleNode(head);

        // Reverse the second half of the list starting from the middle node
        ListNode* secondHalf = reverseLinkedList(middleNodePos);

        // Set the first half to the head of the list
        ListNode* firstHalf = head;

        // Initialize a flag to store the result of the palindrome check
        bool ans = true;

        // Compare the nodes of the first half and the reversed second half
        while (firstHalf != NULL && secondHalf != NULL) {
            // Output the values being compared (for debugging)
            cout << "first half value: " << firstHalf->val << endl;
            cout << "second half value: " << secondHalf->val << endl;

            // If values don't match, set ans to false and break the loop
            if (firstHalf->val != secondHalf->val) {
                ans = false;
                break;
            }

            // Move to the next node in both halves
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Restore the second half of the list back to its original form
        reverseLinkedList(middleNodePos);

        // Return whether the list is a palindrome
        return ans;
    }
};
