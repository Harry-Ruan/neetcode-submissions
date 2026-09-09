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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, vector<bool>> meeting;
        int cnt = 0;
        int maximum = 0;
        for(Interval i : intervals){
            meeting[i.start].push_back(true);
            meeting[i.end].push_back(false);
        }
        for (auto& time : meeting){
            for (bool status : time.second){
                if (status) cnt++;
                else cnt--;
            }
            maximum = max(maximum, cnt);
        }
        return maximum;
    }
};
