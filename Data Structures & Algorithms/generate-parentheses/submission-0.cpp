class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string tracking = "";
        backtracking(n, n, tracking);
        return res;
    }

    void backtracking(int remaining1, int remaining2, string& tracking){
        if (remaining1 == 0 && remaining2 == 0){
            string tmp = tracking;
            res.push_back(tmp); // solve?
            return;
        }
        if (remaining1 < remaining2){
            tracking += ')';
            backtracking(remaining1, remaining2 - 1, tracking);
            tracking.pop_back();
        }
        if (remaining1 > 0){
            tracking += '(';
            backtracking(remaining1 - 1, remaining2, tracking);
            tracking.pop_back();
        }
    }
};
