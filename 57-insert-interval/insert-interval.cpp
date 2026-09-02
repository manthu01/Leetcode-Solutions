class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        // Intervals completely before newInterval
        while(i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add merged interval
        res.push_back(newInterval);

        // Remaining intervals
        while(i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};