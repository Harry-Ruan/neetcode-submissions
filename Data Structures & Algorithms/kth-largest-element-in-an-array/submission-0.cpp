class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minhp;
        for(int i : nums){
            minhp.push(i);
            if (minhp.size() > k) minhp.pop();
        }
        return minhp.top();
    }
};
