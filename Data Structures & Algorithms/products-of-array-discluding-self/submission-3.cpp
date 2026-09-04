class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        bool onezero = false;
        bool dualzero = false;
        vector<int> res(nums.size(), 0);
        for (int i : nums){
            if (i == 0){
                if (onezero){
                    dualzero = true;
                }
                else{
                    onezero = true;
                }
                continue;
            }
            pro = pro * i;
        }
        if (dualzero){
            for (int j = 0; j < nums.size(); j++){
                res[j] = 0;
            }
        }
        else if (onezero){
            for (int j = 0; j < nums.size(); j++){
                if (nums[j] == 0){
                    res[j] = pro;
                }
            }
        }
        else{
            for (int j = 0; j < nums.size(); j++){
                res[j] = pro / nums[j];
            }
        }
        return res;
    }
};
