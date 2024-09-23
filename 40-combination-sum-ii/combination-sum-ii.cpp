#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to generate all combinations
    // 'ans' stores all the valid combinations found
    // 'subset' stores the current combination being formed
    // 'candidates' is the input array of numbers (sorted to handle duplicates)
    // 'index' keeps track of the current element in 'candidates' being considered
    // 'target' is the remaining sum we need to achieve
    void combinationSumHelper(vector<vector<int>>& ans, vector<int>& subset, vector<int>& candidates, int index, int target) {
        // If the target is zero, we have found a valid combination
        if (target == 0) {
            ans.push_back(subset); // Add the current combination to the result
            return;
        }
        
        // Iterate through candidates starting from 'index'
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates to avoid repeating the same combination
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            // If the candidate exceeds the target, no point in continuing
            if (candidates[i] > target) {
                break; // Early exit from the loop
            }
            // Include the current candidate in the subset
            subset.push_back(candidates[i]);
            // Recur with updated index and reduced target
            combinationSumHelper(ans, subset, candidates, i + 1, target - candidates[i]);
            // Backtrack by removing the last added candidate
            subset.pop_back();
        }
    }

public:
    // Main function to find all unique combinations that sum up to the target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to facilitate duplicate handling
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; // Stores all the possible combinations
        vector<int> subset;      // Temporary array to store each valid combination
        // Start the recursive helper function from index 0
        combinationSumHelper(ans, subset, candidates, 0, target);
        return ans; // Return the final list of combinations
    }
};
