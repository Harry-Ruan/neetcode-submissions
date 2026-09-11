class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> pre;
        stack<int> steps;
        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--){
            int cnt = 1;
            while (!pre.empty() && temperatures[i] >= pre.top()){
                pre.pop();
                cnt += steps.top();
                steps.pop();
            }
            if (pre.empty()){
                res[i] = 0;
            }
            else{
                res[i] = cnt;
            }
            pre.push(temperatures[i]);
            steps.push(res[i]);
        }
        return res;
    }
};
