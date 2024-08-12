class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // In case k is greater than n

        // Reverse the last k elements
        reverse(nums.end()-k, nums.end());
        // Reverse the first n-k elements
        reverse(nums.begin(), nums.begin()+(n-k));
        // Reverse the entire array to get the rotated result
        reverse(nums.begin(), nums.end());
    }
};
