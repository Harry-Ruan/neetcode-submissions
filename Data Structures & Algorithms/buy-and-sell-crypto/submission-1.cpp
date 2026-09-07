class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int r = 0;
        int l = 0;
        while (r < prices.size()){
            if (prices[r] < prices[l]) l = r;
            else maxp = max(maxp, prices[r] - prices[l]);
            r++;
        }
        return maxp;
    }
};
