class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         // map from num-fq
        int sz = nums.size();
        unordered_map<int, int> fq;
        vector<vector<int>> bucket(sz + 1);
        vector<int> res;
        for (int i : nums){
            fq[i]++;
        }
        for (auto &p : fq){
            int frequency = p.second;
            int num = p.first;
            bucket[frequency].push_back(num);
        }
        int addedcnt = 0;
        for (int i = sz; i >= 0; i--){
            if (!bucket[i].empty()){
                for (int j : bucket[i]){
                    if(addedcnt < k){
                        res.push_back(j);
                        addedcnt++;
                    }
                }
            }
            if (addedcnt >= k) break;
        }
        return res;
    }
};

//bucket sort!!!