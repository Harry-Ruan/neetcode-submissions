class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int addition = 1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    if (i == 0){
                        addition = 0;
                        matrix[0][j] = 0;
                    }
                    else{
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < m; i++){
            if (!matrix[i][0]) setrow(matrix, i);
        }
        for (int j = 1; j < n; j++){
            if (!matrix[0][j])setcol(matrix, j);
        }
        if (!matrix[0][0]) setcol(matrix, 0);
        if (!addition) setrow(matrix, 0);
    }
    
    void setcol(vector<vector<int>>& matrix, int col){
        for (int i = 0; i < matrix.size(); i++){
            matrix[i][col] = 0;
        }
    }

    void setrow(vector<vector<int>>& matrix, int row){
        for (int i = 0; i < matrix[0].size(); i++){
            matrix[row][i] = 0;
        }
    }
};
