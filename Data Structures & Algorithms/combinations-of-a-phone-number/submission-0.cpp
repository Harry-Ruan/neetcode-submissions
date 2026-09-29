class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        unordered_map<char, string> mp = {
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"},  {'7', "pqrs"},
    {'8', "tuv"}, {'9', "wxyz"}
    };
        vector<string> res;
        string track = "";
        dfs(res, mp, digits, track, 0);
        return res;
    }

    void dfs(vector<string>& res, unordered_map<char, string>& mp, string& digits, string& track, int index){
        if (index == digits.size()) res.push_back(track);
        for (char cur : mp[digits[index]]){
            track.push_back(cur);
            dfs(res, mp, digits, track, index+1);
            track.pop_back();
        }
    }
};
