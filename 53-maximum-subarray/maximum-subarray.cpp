class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize 'maximum' with the first element of the array
        // This will store the maximum subarray sum
        int maximum = nums[0];

        // Initialize 'sum' as 0 to store the current subarray sum
        int sum = 0;

        // Traverse through each element in the array
        for(int i = 0; i < nums.size(); i++) {
            // Add the current element to the 'sum'
            sum += nums[i];

            // Update 'maximum' if the current subarray sum is greater than the previous maximum
            maximum = max(sum, maximum);

            // If the current subarray sum becomes negative, reset it to 0
            // (because continuing with a negative sum will not help maximize the subarray sum)
            if(sum < 0) {
                sum = 0;
            }
        }

        // Return the maximum subarray sum found
        return maximum;
    }
};
