class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur = {};
        backtracking(nums, cur, 0);
        return res;
    }

    void backtracking(vector<int>& nums, vector<int>& cur, int index){
        vector<int> tmp = cur;
        res.push_back(tmp);
        for(int i = index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtracking(nums, cur, i+1);
            cur.pop_back();
        }
    }
};
