class Solution {
public:
    int solve(const string& text1, const string& text2, int i, int j, vector<vector<int>>& dp) {
        // Base case: If either string is exhausted, return 0
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        
        // Check if the result is already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // If characters match, take 1 plus the result from the next characters
        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
        } else {
            // If characters don't match, choose the maximum from either ignoring a character from text1 or text2
            dp[i][j] = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
        }
        
        return dp[i][j];
    }

    int longestCommonSubsequence(const string& text1, const string& text2) {
        // Initialize dp table with -1
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        
        // Call the recursive function
        return solve(text1, text2, 0, 0, dp);
    }
};
