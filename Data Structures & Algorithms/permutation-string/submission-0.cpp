class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> need;
        unordered_map<char, int> cur;
        int cursz = 0;
        for (char c : s1){
            need[c]++;
        }
        int valid = 0;
        while (r < s2.size()){
            cursz++;
            if (need.count(s2[r])){
                cur[s2[r]]++;
                if (cur[s2[r]] == need[s2[r]]){
                    valid++;
                }
            }
            if (cursz > s1.size()){
                if (need.count(s2[l])){
                    if (cur[s2[l]] == need[s2[l]]){
                        valid--;
                    }
                    cur[s2[l]]--;
                }
                l++;
            }
            if (valid == need.size()) return true;
            r++;
        }
        return false;
    }
};
