class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        
        // Sort intervals based on the start times
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for (int i = 1; i < n; ++i) {
            if (ans.back()[1] >= intervals[i][0]) {
                // Merge intervals
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // No overlap, add the new interval
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};
