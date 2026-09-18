class KthLargest {
public:
    int sz;
    int limit;
    priority_queue<int, vector<int>, greater<int>> minhp;
    vector<int> data;
    KthLargest(int k, vector<int>& nums) {
        sz = 0;
        limit = k;
        for (int i : nums){
            add(i);
        }
    }
    
    int add(int val) {
        data.push_back(val);
        if (sz <= limit || val > minhp.top()){
            minhp.push(val);
            sz++;
            if (sz > limit){
                minhp.pop();
            }
        }
        return minhp.top();
    }
};
