class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maximum(nums.size() + 1, 1);
        vector<int> minimum(nums.size() + 1, 1);
        int maxi = -INT_MAX;
        for (int i = nums.size() - 1; i >= 0; i--){
            minimum[i] = min(minimum[i+1] * nums[i], min(nums[i], maximum[i+1] * nums[i]));
            maximum[i] = max(maximum[i+1] * nums[i], max(nums[i], minimum[i+1] * nums[i]));
            maxi = max(maxi, maximum[i]);
        }
        return maxi;
    }
};
