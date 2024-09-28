class Solution {
public:
int climbStairs_memoization(int n,vector<int>&dp) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        int one_step = climbStairs_memoization(n - 1,dp);
        int two_step = climbStairs_memoization(n - 2,dp);
        dp[n]= (one_step + two_step);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climbStairs_memoization(n,dp);
    }
};