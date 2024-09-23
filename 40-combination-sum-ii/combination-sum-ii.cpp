class Solution {
    private:
    // Helper function to generate all combinations
    // 'ans' stores all the valid combinations
    // 'subset' stores the current combination being formed
    // 'candidates' is the input array of numbers
    // 'index' keeps track of the current element in 'candidates' being considered
    // 'target' is the remaining sum we need to achieve
    void combinationSumHelper(vector<vector<int>>& ans, vector<int>& subset,vector<int>& candidates, int index, int target) 
    {
        if (target == 0) {
    ans.push_back(subset);
    return;
  }
      for(int i = index; i <candidates.size();i++){
        if(i > index and candidates[i] == candidates[i-1]){
            continue;
        }
        if(candidates[i]>target) break;
        subset.push_back(candidates[i]);
        combinationSumHelper(ans,subset,candidates,i+1,target-candidates[i]);
        subset.pop_back();
      }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;   // Stores all the possible combinations
        vector<int> subset;        // Temporary array to store each valid combination
        combinationSumHelper(ans, subset, candidates, 0, target); // Start recursion from index 0
        // Sort each inner vector
    // for(auto& it : ans) {
    //     sort(it.begin(), it.end());
    // }

    // // Print sorted inner vectors
    // for(auto it : ans) {
    //     for(auto elem : it) {
    //         cout << elem << " ";
    //     }
    //     cout << endl; // New line after each sorted vector
    // }
    //     set<vector<int>>ss(ans.begin(),ans.end());
    //     vector<vector<int>>ans2;
    //     for(auto it:ss){
    //         ans2.push_back(it);
    //     }
        return ans;  // Return the final list of combinations
    }
};