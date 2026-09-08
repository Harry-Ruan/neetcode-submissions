/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        unordered_map<int, bool> interval;
        for (Interval i : intervals){
            for (int t = i.start; t < i.end; t++){
                if (interval[t]) return false;
                interval[t] = true;
            }
        }
        return true;
    }
};
