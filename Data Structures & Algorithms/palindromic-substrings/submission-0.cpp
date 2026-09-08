class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            res += count(s, 1, i, i);
            res += count(s, 0, i+1, i);
        }
        return res;
    }

    int count(string& s, int init, int left, int right){
        int l = left;
        int r = right;
        int cnt = init;
        while (l-1 >= 0 && r+1 < s.size() && s[l-1] == s[r+1]){
            l--;
            r++;
            cnt++;
        }
        return cnt;
    }
};
