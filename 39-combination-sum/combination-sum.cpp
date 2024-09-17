class Solution {
private:
    // Helper function to generate all combinations
    // 'ans' stores all the valid combinations
    // 'subset' stores the current combination being formed
    // 'candidates' is the input array of numbers
    // 'index' keeps track of the current element in 'candidates' being considered
    // 'target' is the remaining sum we need to achieve
    void combinationSumHelper(vector<vector<int>>& ans, vector<int>& subset,
                              vector<int>& candidates, int index, int target) {
        // Base case: If we've reached the end of the candidates array
        if (index == candidates.size()) {
            // If target is zero, we found a valid combination, add it to 'ans'
            if (target == 0) {
                ans.push_back(subset);
            }
            return;
        }

        // Check if the current candidate can be used (if it doesn't exceed the target)
        if (target >= candidates[index]) {
            // Include the current candidate in the subset
            subset.push_back(candidates[index]);

            // Recursively call the function with the same index (candidate can be reused)
            combinationSumHelper(ans, subset, candidates, index, target - candidates[index]);

            // Backtrack: remove the last candidate added (explore other possibilities)
            subset.pop_back();
        }

        // Move to the next candidate and explore further combinations
        combinationSumHelper(ans, subset, candidates, index + 1, target);
    }

public:
    // Main function that initiates the combination sum process
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;   // Stores all the possible combinations
        vector<int> subset;        // Temporary array to store each valid combination
        combinationSumHelper(ans, subset, candidates, 0, target); // Start recursion from index 0
        return ans;  // Return the final list of combinations
    }
};
