class Solution {
public:
    int minDistance(string word1, string word2) {
        int p1 = 0;
        int p2 = 0;
        vector<vector<int>> memo(word1.size(), vector<int> (word2.size(), -1));
        return dp(word1, word2, memo, p1, p2);

    }
    
    int dp(string& word1, string& word2, vector<vector<int>>& memo, int p1, int p2){
        if (p1 == word1.size() && p2 == word2.size()) return 0;
        else if (p1 == word1.size()) return word2.size() - p2;
        else if (p2 == word2.size()) return word1.size() - p1;
        if (word1[p1] == word2[p2]) memo[p1][p2] = dp(word1, word2, memo, p1+1, p2+1);
        else {
            if (memo[p1][p2] != -1) return memo[p1][p2];
            memo[p1][p2] = min(dp(word1, word2, memo, p1+1, p2) + 1, min(dp(word1, word2, memo, p1, p2+1) +1, dp(word1, word2, memo, p1+1, p2+1)+1));
        }
        return memo[p1][p2];
    }
};
