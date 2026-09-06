class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int res = 0;
        for (int i : nums){
            if (!numset.count(i - 1)){
                int cnt = 0;
                while (numset.count(cnt + i)){
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
