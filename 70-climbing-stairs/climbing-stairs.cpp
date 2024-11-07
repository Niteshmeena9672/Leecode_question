class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(46,-1) ; //(size, value)
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i <=n ; i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};