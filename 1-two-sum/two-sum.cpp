class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mpp; // Hash map to store value and its index

    for (int i = 0; i < n; i++) {
        mpp[nums[i]] = i; // Store the index of each number
    }

    for (int i = 0; i < n; i++) {
        int remaining_value = target - nums[i];
        // Check if the remaining value exists and its index is not the same as the current index
        if (mpp.find(remaining_value) != mpp.end() && mpp[remaining_value] != i) {
            return {i, mpp[remaining_value]}; // Return the indices
        }
    }
    return {-1, -1}; // Return {-1, -1} if no solution is found
}
};