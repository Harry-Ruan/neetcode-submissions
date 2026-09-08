class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> order;
        for (int i = 0; i < nums.size()-1; i++){
            order.push_back(nums[i]);
        }
        vector<int> reverse;
        for (int i = nums.size() - 1; i > 0; i--){
            reverse.push_back(nums[i]);
        }
        return max(robhelper(order), robhelper(reverse));
    }

    int robhelper(vector<int>& nums){
        vector<int> save(nums.size() + 1, 0);
        save[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--){
            save[i] = max(nums[i] + save[i+2], save[i+1]);
        }
        return save[0];
    }
};
