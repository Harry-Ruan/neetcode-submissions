class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxpro(prices.size(), -1);
        return dp(prices, maxpro, 0, 1);
    }

    int dp(vector<int>& prices, vector<int>& maxpro, int l, int r){
        int profit = 0;
        if (r >= prices.size()) return 0;
        if (maxpro[l] >= 0) return maxpro[l];
        while (r < prices.size() && prices[l] < prices[r]){
            profit = max(prices[r] - prices[l] + dp(prices, maxpro, r+2, r+3), profit);
            r++;
        }
        maxpro[l] = max(profit, dp(prices, maxpro, r, r+1));
        return maxpro[l];
    }
};
