class TimeMap {
public:
    unordered_map<string, vector<string>> pairs;
    unordered_map<string, vector<int>> timestamps;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pairs[key].push_back(value);
        timestamps[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if (!pairs.count(key)) return "";
        vector<int> times = timestamps[key];
        int idx = findidx(0, times.size()-1, times, timestamp);
        if (idx == -1) return "";
        else return pairs[key][idx];
    }

    int findidx(int l, int r, vector<int>& times, int target){
        int mid = l + (r - l)/2;
        if (l == r){
            if (times[mid] > target) return -1;
            else return mid;
        }
        if (times[mid] <= target && times[mid+1] > target){
            return mid;
        }
        else if (times[mid+1] <= target) return findidx(mid+1, r, times, target);
        else return findidx(l, mid, times, target);
    }
};
