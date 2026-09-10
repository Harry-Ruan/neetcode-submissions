class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> startwith(s.size() + 1, false);
        startwith[s.size()] = true;
        for (int idx = s.size() - 1; idx >= 0; idx--){
            for (string word : wordDict){
                if (idx + word.size() <= s.size()){
                    startwith[idx] = (startwith[idx + word.size()] && s.substr(idx, word.size()) == word);
                }
                if (startwith[idx]) break;
            } 
        }
        return startwith[0];
    }
};
