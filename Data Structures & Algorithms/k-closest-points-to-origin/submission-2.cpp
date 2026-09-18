class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype([](auto& a, auto& b){return pow(a[0], 2) + pow(a[1], 2) < pow(b[0], 2) + pow(b[1], 2);})> maxhp;
        vector<vector<int>> res;
        for (vector<int> v : points){
            maxhp.push(v);
            if (maxhp.size() > k) maxhp.pop();
        }
        while(!maxhp.empty()){
            res.push_back(maxhp.top());
            maxhp.pop();
        }
        return res;
    }
};
