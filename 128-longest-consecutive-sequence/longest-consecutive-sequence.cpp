class Solution {
public:
    int longestConsecutiveSubsequence(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        
        // Mark all elements in the map as not visited
        for (int i = 0; i < n; i++) {
            mpp[nums[i]] = 0;
        }
        
        int longest_sequence = 0;

        for (int i = 0; i < n; i++) {
            if (mpp[nums[i]] != 1) {
                int curr_sequence = 0;
                int starting_number = nums[i];
                
                // Find the smallest starting number of the sequence
                while (mpp.find(starting_number - 1) != mpp.end()) {
                    starting_number -= 1;
                }
                
                // Count the length of the sequence starting from the smallest number
                while (mpp.find(starting_number) != mpp.end()) {
                    curr_sequence += 1;
                    mpp[starting_number] = 1; // Mark as visited
                    starting_number += 1;
                }
                
                longest_sequence = max(curr_sequence, longest_sequence);
            }
        }
        
        return longest_sequence;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        return longestConsecutiveSubsequence(nums);
    }
};
