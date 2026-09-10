class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;
        while (l < r){
            for (int y = l; y < r; y++){
                fourrotate(l, y, matrix);
            }
            l++;
            r--;
        }
    }

    void fourrotate(int x, int y, vector<vector<int>>& matrix){
        int n = matrix.size();
        // first
        int tmp = matrix[y][n-1-x];
        matrix[y][n-1-x] = matrix[x][y];
        int prev = tmp;
        //second
        tmp = matrix[n-1-x][n-1-y];
        matrix[n-1-x][n-1-y] = prev;
        prev = tmp;
        //third
        tmp = matrix[n-1-y][x];
        matrix[n-1-y][x] = prev;
        prev = tmp;
        //fourth
        tmp = matrix[x][y];
        matrix[x][y] = prev;
        prev = tmp;
    }
};
