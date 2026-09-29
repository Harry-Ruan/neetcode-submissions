class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mincost(cost.size(), INT_MAX);
        mincost[0] = cost[0];
        mincost[1] = cost[1];
        for (int i = 0; i < cost.size(); i++){
            if (i+1 < cost.size()){
                mincost[i+1] = min(mincost[i+1], mincost[i]+cost[i+1]);
            }
            if (i+2 < cost.size()){
                mincost[i+2] = min(mincost[i+2], mincost[i]+cost[i+2]);
            }
        }
        return min(mincost[cost.size()-1], mincost[cost.size()-2]);
    }
};
