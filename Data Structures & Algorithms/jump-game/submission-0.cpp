class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> range(nums.size(), false);
        range[0] = true;
        for (int i = 0; i < nums.size() - 1; i++){
            int step = nums[i];
            int sz;
            if (step + i > nums.size() - 1) sz = nums.size() - 1;
            else sz = step + i;
            for (int j = i + 1; j <= sz; j++){
                range[j] = true;
            }
        }
        for (int k = 0; k < range.size(); k++){
            if (!range[k]) return false;
        }
        return true;
    }
};
