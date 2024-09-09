class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize 'min_value' to the first price (assume buying at the first day)
        int min_value = prices[0];

        // Initialize 'curr_profit' to store the profit at each step and 'max_profit' to track the highest profit
        int curr_profit = 0;
        int max_profit = 0;

        // Get the total number of days
        int n = prices.size();

        // Loop through all the prices
        for(int i = 0; i < n; i++) {
            // Calculate the current profit if we sell on day i, by subtracting the minimum buying price so far
            curr_profit = prices[i] - min_value;

            // Update the maximum profit if the current profit is higher
            max_profit = max(max_profit, curr_profit);

            // Update 'min_value' with the minimum price so far to ensure we're buying at the lowest possible price
            min_value = min(min_value, prices[i]);
        }

        // Return the maximum profit obtained
        return max_profit;
    }
};
