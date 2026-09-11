class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = bfscol(0, matrix.size() - 1, target, matrix);
        return bfsrow(0, matrix[0].size() - 1, target, col, matrix);
    }

    int bfscol(int l, int r, int target, vector<vector<int>>& matrix){
        int mid = (l + r) / 2 + 1;
        if (r == l) return l;
        else if (target < matrix[mid][0]) return bfscol(l, mid - 1, target, matrix);
        else return bfscol(mid, r, target, matrix);
    }

    bool bfsrow(int l, int r, int target, int col, vector<vector<int>>& matrix){
        int mid = (l + r) / 2;
        if (target == matrix[col][mid]) return true;
        else if (r == l) return false;
        else if (target <= matrix[col][mid]) return bfsrow(l, mid, target, col, matrix);
        else return bfsrow(mid + 1, r, target, col, matrix);
    }
};
