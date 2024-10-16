#include <vector>
using namespace std;

class Solution {
public:
    int coin_change_helper(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp) {
        int n = coins.size();

        // Check if this state has already been computed
        if (dp[idx][amount] != -1) return dp[idx][amount];

        // If the amount is zero, we found one way to make change
        if (amount == 0) return dp[idx][amount] = 1;
        // If index goes out of bounds, we cannot form the amount
        if (idx == n) return dp[idx][amount] = 0;
        // If current coin exceeds the amount, we cannot use it
        if (coins[idx] > amount) return dp[idx][amount] = coin_change_helper(coins, idx + 1, amount, dp);

        // Consider taking the coin (not moving to the next coin)
        int take = coin_change_helper(coins, idx, amount - coins[idx], dp);
        // Consider not taking the coin (move to the next coin)
        int not_take = coin_change_helper(coins, idx + 1, amount, dp);

        // Save the result in dp array
        return dp[idx][amount] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {
        // Initialize the dp array with -1
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        // Call the helper function with the initialized dp
        return coin_change_helper(coins, 0, amount, dp);
    }
};
