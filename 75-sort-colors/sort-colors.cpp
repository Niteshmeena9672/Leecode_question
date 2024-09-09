class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Initialize three pointers: low for 0s, mid for the current element, and high for 2s
        int mid = 0, low = 0, high = nums.size()-1;

        // Continue until mid crosses high
        while(mid <= high) {
            
            // If the current element is 0, swap it with the element at 'low'
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;  // Increment low pointer since we placed a 0
                mid++;  // Move mid pointer to check the next element
            }
            // If the current element is 1, just move the mid pointer
            else if(nums[mid] == 1) {
                mid++;
            }
            // If the current element is 2, swap it with the element at 'high'
            else {
                swap(nums[mid], nums[high]);
                high--;  // Decrement high pointer since we placed a 2
            }
        }   
    }
};
