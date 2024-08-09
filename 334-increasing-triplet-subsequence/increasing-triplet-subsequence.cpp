class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        for(int num : nums) {
            if(num <= first) {
                first = num;  // update the smallest number
            } else if(num <= second) {
                second = num;  // update the second smallest number
            } else {
                // If we find a number greater than both first and second,
                // it means we have found our increasing triplet subsequence
                return true;
            }
        }
        
        return false;  // No increasing triplet found
    }
};