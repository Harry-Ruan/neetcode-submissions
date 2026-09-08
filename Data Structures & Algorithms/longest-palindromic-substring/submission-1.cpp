class Solution {
public:
    string longestPalindrome(string s) {
        int resl = 0;
        int resr = 0;
        for (int i = 0; i < s.size(); i++){
            vector<int> v = count1(s, i);
            if (v[1] - v[0] > resr - resl){
                resl = v[0];
                resr = v[1];
            }
        }
        for (int i = 0; i < s.size(); i++){
            vector<int> v = count2(s, i);
            if (v[1] - v[0] > resr - resl){
                resl = v[0];
                resr = v[1];
            }
        }
        return s.substr(resl, resr - resl + 1);
    }

    vector<int> count1(string& s, int idx){
        int l = idx;
        int r = idx;
        int len = 1;
        while (l-1 >= 0 && r+1 < s.size() && s[l-1] == s[r+1]){
            l--;
            r++;
            len += 2;
        }
        return {l, r};
    }
    vector<int> count2(string& s, int idx){
        int l = idx+1;
        int r = idx;
        int len = 0;
        while (l-1 >= 0 && r+1 < s.size() && s[l-1] == s[r+1]){
            l--;
            r++;
            len += 2;
        }
        return {l, r};
    }
};
