class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer for the last element in nums1's valid portion
        int j = n - 1; // Pointer for the last element in nums2
        int k = m + n - 1; // Pointer for the last position in nums1 (combined size)

        // Merge the arrays from the back to avoid overwriting elements in nums1
        while (j >= 0) { // Process all elements of nums2
            // If nums1's element is greater than nums2's or nums1 is still valid
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--]; // Place nums1's element at the end and decrement i and k
            } else {
                nums1[k--] = nums2[j--]; // Place nums2's element at the end and decrement j and k
            }
        }
    }
};
