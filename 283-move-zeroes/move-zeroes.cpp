class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; // Pointer for the position to place the next non-zero element
        
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++; // Move the pointer for the next non-zero position
            }
        }
    }
};
