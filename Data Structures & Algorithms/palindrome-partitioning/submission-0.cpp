class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> res;
        res.push_back({{}});
        // + char: 1. end with is a pa 2. original pa num
        for (int end = 0; end < s.size(); end++){
            for (int start = end; start >= 0; start--){
                res.push_back({});
                if (ispalin(s, start, end)){
                    //vector<vector<string>> curres;
                        for (vector<string> ori : res[start]){
                            ori.push_back(s.substr(start, end-start+1));
                            res[end+1].push_back(ori);
                        }
                    }
                }
            }
            return res[s.size()];
    }

    bool ispalin(string& s, int start, int end){
        int l = start;
        int r = end;
        while (l < r){
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
