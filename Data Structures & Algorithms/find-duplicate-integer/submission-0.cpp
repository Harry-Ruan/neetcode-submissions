class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int fast = nums[0];
        int slow = nums[0];
        while (fast != slow){
            fast = nums[fast];
            fast = nums[fast];
            slow = nums[slow];
        }
        int slowb = 0;
        while(slowb != slow){
            slow = nums[slow];
            slowb = nums[slowb];
        }
        return slow;
    }
};
