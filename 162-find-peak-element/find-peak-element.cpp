class Solution {
public:
    int findPeakElement(vector<int>& arr) {
            // Size of array
        int n = arr.size();
        
        /* Iterate through the array
        to find the peak element */
        for (int i = 0; i < n; i++) {
            
            // Check if arr[i] is a peak
            if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1])) {
                
                //Return the index of peak element
                return i; 
            }
        }
        /* Return -1 if no peak element
        found (dummy return) */
        return -1; 
    }
};