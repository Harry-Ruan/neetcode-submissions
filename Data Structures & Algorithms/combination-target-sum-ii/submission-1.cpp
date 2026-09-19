class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur = {};
        backtracking(candidates, cur, 0, 0, target);
        return res;
    }

    void backtracking(vector<int>& candidates, vector<int>& cur, int cursum, int index, int target){
        if (cursum == target){
            vector<int> tmp = cur;
            res.push_back(tmp);
            return;
        }
        for (int i = index; i < candidates.size(); i++){
            if (i > index && candidates[i] == candidates[i-1]) continue;
            if (cursum + candidates[i] > target) break;
                cur.push_back(candidates[i]);
                backtracking(candidates,cur, cursum + candidates[i], i+1, target);
                cur.pop_back();
        }
    }
};

// iterate inside backtracking
