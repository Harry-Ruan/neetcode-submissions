class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tracking = {};
        unordered_map<int, bool> used;
        for (int i : nums){
            used[i] = false;
        }
        backtracking(tracking, used, nums);
        return res;
    }

    void backtracking(vector<int>& tracking, unordered_map<int, bool>& used, vector<int>& nums){
        if (tracking.size() == nums.size()){
            vector<int> tmp = tracking;
            res.push_back(tmp);
            return;
        }
        for (int i : nums){
            if (!used[i]){
                tracking.push_back(i);
                used[i] = true;
                backtracking(tracking, used, nums);
                used[i] = false;
                tracking.pop_back();
            }
        }
    }
};
