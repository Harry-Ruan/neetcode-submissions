class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> save(nums.size(), -1);
        int res = DP(nums, save, 0); 
        return res;
    }

    int DP(vector<int>& nums, vector<int>& save, int idx){
        if (idx == nums.size() - 1) return nums[nums.size() - 1];
        if (idx >= nums.size()) return 0;
        int two;
        int one;
        if (idx + 2 <= nums.size() - 1 && save[idx + 2] >= 0) two = save[idx + 2];
        else{
            two = DP(nums, save, idx + 2);
            if (idx + 2 <= nums.size() - 1) save[idx + 2] = two;
        }
        if (idx + 1 <= nums.size() - 1 && save[idx + 1] >= 0) one = save[idx + 1];
        else{
            one = DP(nums, save, idx + 1);
            if (idx + 1 <= nums.size() - 1) save[idx + 1] = one;
        }
        return max(nums[idx] + two, one);
    }
};
