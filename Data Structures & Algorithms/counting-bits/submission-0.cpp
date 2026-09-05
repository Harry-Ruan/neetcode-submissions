class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        int cnt = 0;
        int offset = 1;
        while (cnt < n){
            cnt++;
            if (cnt == 2 * offset){
                offset *= 2;
            }
            res[cnt] = 1 + res[cnt - offset];
        }
        return res;
    }
};
