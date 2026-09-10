class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int bound = 0;
        int start = 0;
        int direction = 0;
        int x = 0;
        int y = 0;
        vector<int> res;
        res.push_back(matrix[0][0]);
        int sz = matrix.size() * matrix[0].size();
        while(res.size() < sz){
            while(inbound(x, y, bound, start, direction, matrix)){
                go(x, y, direction);
                res.push_back(matrix[x][y]);
            }
            direction = changedir(direction);
        }
        return res;
    }

    int changedir(int cur){
        return (cur + 1) % 4;
    }

    void go(int& x, int& y, int dir){
        if (dir == 0){
            y++;
        }
        else if (dir == 1){
            x++;
        }
        else if (dir == 2){
            y--;
        }
        else{
            x--;
        }
    }

    bool inbound(int x, int y, int& bound, int& start, int dir, vector<vector<int>>& matrix){
        if (dir == 0){
            return (y + 1 < matrix[0].size() - bound);
        }
        if (dir == 1){
            return (x + 1 < matrix.size() - bound);
        }
        if (dir == 2){
            return (y - 1 >= bound);
        }
        if (x - 1 <= start){
            bound++;
            start++;
            return false;
        }
        else return true;
    }
};
