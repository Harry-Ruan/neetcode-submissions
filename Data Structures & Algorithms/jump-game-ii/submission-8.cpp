class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return 0;
        vector<bool> covered(nums.size(), false);
        int maxcover = min(nums[0], sz - 1);
        int step = 0;
        int index = 0;
        while (index < nums.size() - 1){
            step++;
            int curmax = -1;
            for (int i = index + 1; i <= maxcover; i++){
                curmax = max(curmax, i + nums[i]);
            }
            index = maxcover;
            maxcover = min(curmax, sz -1 );
        }
        return step;
    }
};
