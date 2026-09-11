class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum = 0;
        /*for (int i = 0; i < numbers.size(); i++){
            sum += numbers[i];
        } */
        int l = 0;
        int r = numbers.size()-1;
        while (numbers[l] + numbers[r] != target){
            if (numbers[l] + numbers[r] < target){
                l++;
            }
            else{
                r--;
            } 
        }
        vector<int> res;
        /*for (int j = l; j <= r; j++){
            res.push_back(numbers[j]);
        } */
        res.push_back(l+1);
        res.push_back(r+1);
        return res;
    }
};
