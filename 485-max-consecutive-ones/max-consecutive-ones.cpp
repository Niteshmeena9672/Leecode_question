class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         // Initialize variables:
        // curr_length to keep track of the current streak of 1s.
        // max_length to store the maximum length of consecutive 1s found.
        int curr_length = 0;
        int max_length = 0;

        // Iterate through the array
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                // If the current element is 1, increment curr_length
                curr_length++;
                // Update max_length if curr_length is greater
                max_length = max(max_length, curr_length);
            } else {
                // If the current element is 0, reset curr_length to 0
                curr_length = 0;
            }
        }
        // Return the maximum length of consecutive 1s found
        return max_length;    
    }
};