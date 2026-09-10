class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++){
            vector<int> interval = intervals[i];
            if (newInterval[1] < interval[0]){
                res.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            }
            else if (newInterval[0] > interval[1]){
                res.push_back(interval);
            }
            else{
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

// extra space != space