class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;  // Pointers to traverse nums1 and nums2.
        unordered_set<int> ans;   // Vector to store the intersection result.
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size();  // Size of the first array.
        int n2 = nums2.size();  // Size of the second array.

        // Iterate through both arrays until one of them is fully traversed.
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {  // If elements match, add to result.
                ans.insert(nums1[i]);
                i++;  // Move both pointers forward.
                j++;
            } 
            else if (nums1[i] < nums2[j]) {
                i++;  // Move pointer of nums1 forward if its element is smaller.
            } 
            else {
                j++;  // Move pointer of nums2 forward if its element is smaller.
            }
        } 

        vector<int>final_answer;
        for(auto it:ans){
            final_answer.push_back(it);
        }
        return final_answer;

    }
};