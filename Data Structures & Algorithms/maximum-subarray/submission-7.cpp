class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int cursum = 0;
        int l = 0;
        int r = 0;
        while (r < nums.size()){
            if ((nums[r] > 0 || nums[r] > nums[l]) && cursum < 0 ){
                l = r;
                cursum = nums[r];
            }
            else cursum += nums[r];
            maximum = max(cursum, maximum);
            r++; 
        }
        return maximum;
    }
};
