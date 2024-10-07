class Solution {
public:
    int helper(vector<int> &house,vector<int>&dp, int curr_index) {
        if (curr_index >= house.size() )
            return 0;
        if(dp[curr_index]!=-1){
            return dp[curr_index];
        }
        int steal = house[curr_index] + helper(house,dp, curr_index + 2);
        int skip = helper(house,dp, curr_index + 1);
        return dp[curr_index] = max(steal, skip);
    }

        int rob(vector<int> & nums) {
            vector<int>dp(101,-1);
            return helper(nums,dp, 0);
        }
    };