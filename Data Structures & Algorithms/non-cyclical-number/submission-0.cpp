class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int cur = n;
        while (!seen.count(cur)){
            seen.insert(cur);
            cur = power(cur);
        }
        if (cur == 1) return true;
        else return false;
    }

    int power(int cur){
        int sum = 0;
        while(cur){
            sum += (cur % 10) * (cur % 10);
            cur = cur / 10;
        }
        return sum;
    }
};
