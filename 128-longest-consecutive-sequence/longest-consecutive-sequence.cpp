class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueNums;  // Set to store unique numbers from the input
        int maxConsecutiveLength = 0;   // Variable to track the longest consecutive sequence

        // Insert all elements into the unordered set to eliminate duplicates
        for(auto num : nums){
            uniqueNums.insert(num);
        }

        // Iterate through the set to find the longest consecutive sequence
        for(auto num : uniqueNums){
            // Check if the current number is the start of a sequence
            if(uniqueNums.find(num - 1) == uniqueNums.end()){
                int currentConsecutiveLength = 1;  // Length of the current consecutive sequence
                int currentNum = num;  // Variable to track the current number in the sequence

                // Check for the next numbers in the sequence
                while(uniqueNums.find(currentNum + 1) != uniqueNums.end()){
                    currentConsecutiveLength++;  // Increase the sequence length
                    currentNum++;  // Move to the next number in the sequence
                }

                // Update the maximum consecutive sequence length if the current one is longer
                maxConsecutiveLength = max(maxConsecutiveLength, currentConsecutiveLength);
            }
        }

        return maxConsecutiveLength;  // Return the length of the longest consecutive sequence
    }
};
