class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int l = 0;
        int r = sz - 1;

        // search smallest
        while(l < r){
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[sz - 1]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        int index = l;
        int smallest = nums[l];
        if (target < smallest){
            return -1;
        }
        if (target <= nums[sz - 1]){
            // search right;
            r = sz - 1;
            while (l < r){
                int mid1 = l + (r - l) / 2;
                if (nums[mid1] < target){
                    l = mid1 + 1;
                }
                else{
                    r = mid1;
                }
            }
            if (nums[l] != target){
                return -1;
            }
            return l;
        }
        else{
            // search left
            r = index;
            l = 0;
            while(l < r){
                int mid2 = l + (r - l) / 2;
                if (nums[mid2] < target){
                    l = mid2 + 1;
                }
                else{
                    r = mid2;
                }
            }
            if (nums[l] != target){
                return -1;
            }
            return l;
        }
    }
};
