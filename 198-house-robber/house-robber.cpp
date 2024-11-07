class Solution {
public:

     int helper (vector<int>&house , int curr_index, vector<int>&dp){
        if(curr_index>= house.size()) return 0;
        if(dp[curr_index]!=-1) return dp[curr_index];
        int steal = house[curr_index] + helper(house,curr_index+2 , dp);
        int notSteal = helper(house,curr_index+1, dp);
        return dp[curr_index]= max(steal, notSteal);
     }
    // int helper(vector<int> &house,vector<int>&dp, int curr_index) {
    //     if (curr_index >= house.size() )
    //         return 0;
    //     if(dp[curr_index]!=-1){
    //         return dp[curr_index];
    //     }
    //     int steal = house[curr_index] + helper(house,dp, curr_index + 2);
    //     int skip = helper(house,dp, curr_index + 1);
    //     return dp[curr_index] = max(steal, skip);
    // }

    int tabulation(vector<int> &house, vector<int>& dp) {
        dp[0] = 0;
        int n = house.size();
        dp[1] = house[0];
        for (int i = 2; i <= n; i++) {
            int steal = house[i-1] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(steal, skip);
        }
        return dp[house.size()];
    }

        int rob(vector<int> & nums) {
            vector<int> dp(101, -1);
            // return tabulation(nums, dp);
            return helper(nums, 0,dp);
        }
    };