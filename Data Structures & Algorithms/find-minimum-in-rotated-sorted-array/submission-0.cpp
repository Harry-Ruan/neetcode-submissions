class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // 如果 mid 元素大于右边界元素，说明最小值一定在 mid 右侧
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else { // 否则最小值在 mid 或 mid 左侧
                r = mid;
            }
        }
        return nums[l];
    }
};