class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 0);
        LIS[nums.size()-1] = 1;
        int maximum = 1;
        for (int start = nums.size()-2; start >= 0; start--){
            int curmax = 1;
            for (int i = start + 1; i < nums.size(); i++){
                if (nums[start] < nums[i]) curmax = max(1 + LIS[i], curmax);
            }
            LIS[start] = curmax;
            maximum = max(curmax, maximum);
        }
        return maximum;
    }
};
