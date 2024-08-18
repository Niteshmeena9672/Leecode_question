class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Initialize two variables for XOR operations
        // xor1 will hold the XOR of all elements in the array
        // xor2 will hold the XOR of all numbers from 1 to n
        int xor1 = 0, xor2 = 0;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // XOR all the elements in the array with xor1
            xor1 = xor1 ^ nums[i];
            // XOR all the numbers from 1 to n with xor2
            xor2 = xor2 ^ (i + 1);
        }

        // The missing number is found by XORing xor1 and xor2
        // This works because XORing a number with itself cancels out, 
        // leaving the missing number as the result
        return (xor1 ^ xor2);
    }
};
