class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;  // Initialize idx to -1 to indicate no valid index found yet
        int n = nums.size();  // Get the size of the array

        // Find the first index from the end where the current element is smaller than the next one
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;  // Store the index
                break;  // Exit loop as soon as the first such index is found
            }
        }

        if(idx == -1){
            // If no such index is found, the array is in descending order
            // Reverse the entire array to get the smallest permutation
            reverse(nums.begin(), nums.end());
        } else {
            // Find the first element from the end that is greater than nums[idx]
            for(int i = n-1; i > idx; i--){
                if(nums[i] > nums[idx]){
                    // Swap the elements at idx and i
                    swap(nums[i], nums[idx]);

                    // Reverse the subarray to the right of idx to get the next permutation
                    reverse(nums.begin() + idx + 1, nums.end());
                    break;  // Exit loop once the swap and reverse are done
                }
            }
        }
    }
};
