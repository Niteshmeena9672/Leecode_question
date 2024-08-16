class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minElement = arrays[0].front();
        int maxElement = arrays[0].back();
        int maxDist = 0;
        
        for (int i = 1; i < arrays.size(); ++i) {
            // Calculate distance between current array's max and min element of other arrays
            maxDist = max(maxDist, abs(arrays[i].back() - minElement));
            // Calculate distance between current array's min and max element of other arrays
            maxDist = max(maxDist, abs(maxElement - arrays[i].front()));
            
            // Update minElement and maxElement for the next iteration
            minElement = min(minElement, arrays[i].front());
            maxElement = max(maxElement, arrays[i].back());
        }
        
        return maxDist;
    }
};