class Solution {
public:
    int climbStairs_memoization(int n, vector<int>& dp) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (dp[n] != -1)
            return dp[n];
        int one_step = climbStairs_memoization(n - 1, dp);
        int two_step = climbStairs_memoization(n - 2, dp);
        dp[n] = (one_step + two_step);
        return dp[n];
    }
    int climbStairs_tabulation(int n, vector<int>& dp) {
        dp[0]=1;
        dp[1]=1;
        for(int i = 2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climbStairs_tabulation(n, dp);
    }
};