class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // // Step 1: Insert all elements into a set (automatically removes duplicates)
        // set<int> uniqueElements(nums.begin(), nums.end());
        
        // // Step 2: Replace elements in nums with elements from the set
        // int index = 0;
        // for (int element : uniqueElements) {
        //     nums[index++] = element;
        // }
        
        // // The number of unique elements is the size of the set
        // return uniqueElements.size();

        // Step 1: Get the size of the input array
        int n = nums.size();
        
        // Step 2: Initialize two pointers, i and j
        // i: Tracks the position of the last unique element
        // j: Scans through the array starting from the second element
        int i = 0, j = 1;
        
        // Step 3: Traverse the array with pointer j
        for(; j < n; j++) {
            // If a unique element is found (nums[j] != nums[i])
            if (nums[j] != nums[i]) {
                // Move i to the next position and update with the unique element
                nums[++i] = nums[j];
            }
        }
        
        // Step 4: Return the number of unique elements
        // This is i + 1 because i is the index and indexing starts from 0
        return i + 1;
    }
};
