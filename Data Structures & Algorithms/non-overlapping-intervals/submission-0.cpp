class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a[1] < b[1];});
        int newEnd = intervals[0][1];
        int res = 0;
        for (int i = 0; i < intervals.size() - 1; i++){
            if (newEnd > intervals[i+1][0]){
                newEnd = min(newEnd, intervals[i+1][1]);
                res++;
            }
            else{
                newEnd = intervals[i+1][1];
            }
        }
        return res;
    }
};
