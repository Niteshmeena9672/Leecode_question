class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];  // Start slow at the first element
        int fast = nums[0];  // Start fast at the first element

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];          // Slow moves 1 step
            fast = nums[nums[fast]];    // Fast moves 2 steps
        } while (slow != fast);         // Loop until slow and fast meet

        // Phase 2: Find the entrance to the cycle
        slow = nums[0];  // Reset slow to the start of the array
        while (slow != fast) {
            slow = nums[slow];  // Both pointers move 1 step at a time
            fast = nums[fast];
        }

        return slow;  // This is the duplicate number
    }
};
