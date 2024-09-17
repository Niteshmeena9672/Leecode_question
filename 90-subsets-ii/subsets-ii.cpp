class Solution {
private:
    // Helper function to generate subsets, avoiding duplicates
    void subsetsWithoutDupHelper(vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans, int idx, int n) {
        // Add the current subset to the answer
        ans.push_back(subset);
        
        // Loop through the remaining elements starting from the current index
        for (int i = idx; i < n; i++) {
            // Skip duplicate elements to avoid generating duplicate subsets
            if (i != idx && nums[i] == nums[i - 1]) {
                continue; // Move to the next iteration
            }
            
            // Include the current element in the subset
            subset.push_back(nums[i]);
            
            // Recursively generate subsets starting from the next index
            subsetsWithoutDupHelper(nums, subset, ans, i + 1, n);
            
            // Backtrack by removing the last added element to explore other possibilities
            subset.pop_back();
        }
    }

public:
    // Main function to generate all subsets of the array, avoiding duplicates
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the array to group duplicate elements together
        sort(nums.begin(), nums.end());
        
        // Get the size of the array
        int n = nums.size();
        
        // Vector to store all subsets
        vector<vector<int>> ans;
        
        // Temporary vector to hold the current subset being generated
        vector<int> subset;
        
        // Call the helper function to generate subsets starting from index 0
        subsetsWithoutDupHelper(nums, subset, ans, 0, n);
        
        // Return the final list of subsets
        return ans;
    }
};
