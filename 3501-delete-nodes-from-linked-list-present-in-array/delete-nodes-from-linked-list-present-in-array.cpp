#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        // Populate the hash map with values from the vector
        for (int i = 0; i < n; ++i) {
            mpp[nums[i]]++;
        }

        // Create a dummy node to handle the edge case of deleting the head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        // Traverse the list and remove nodes with values in the hash map
        while (curr != nullptr) {
            if (mpp.find(curr->val) != mpp.end()) {
                // Node to delete
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                // Move to the next node
                prev = curr;
                curr = curr->next;
            }
        }

        // Return the new head
        return dummy.next;
    }
};
