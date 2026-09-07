class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int climb1 = 1;
        int climb2 = 2;
        for (int i = 3; i <= n; i++){
            int climbi = climb1 + climb2;
            climb1 = climb2;
            climb2 = climbi;
        }
        return climb2;
    }
};
