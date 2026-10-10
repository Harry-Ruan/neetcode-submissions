class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> res(amount+1,0);
        res[0]=1;
        for (int coin : coins){
            for (int remain = 0; remain <= amount; remain+=1){
                if (remain-coin>=0) res[remain] += res[remain-coin];
            }
        }
        return res[amount];
    }
};
