class Solution {
public:
    int getSum(int a, int b) {
        while (b){
            int tmp = a;
            a = a ^ b;
            b = (b & tmp) << 1;
        }
        return a;
    }
};
