class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bfs(0, nums.size() - 1, target, nums);
    }

    int bfs(int l, int r, int target, vector<int>& nums){
        int mid = (l + r) / 2;
        if (target == nums[mid]) return mid;
        else if (r == l) return -1;
        else if (target <= nums[mid]) return bfs(l, mid, target, nums);
        else return bfs(mid + 1, r, target, nums);
    }
};
