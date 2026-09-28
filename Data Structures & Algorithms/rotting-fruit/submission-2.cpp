class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> pq;
        vector<pair<int, int>> adjacent = {{0,1}, {0, -1}, {1,0}, {-1,0}};
        int round = 0;
        bool hasIni = false;
        int m = grid.size();
        int n = grid[0].size();
        for (int x = 0; x < grid.size(); x++){
            for (int y = 0; y < grid[0].size(); y++){
                if (grid[x][y]==2){
                    pq.push({x,y});
                    grid[x][y] = -1;
                    hasIni = true;
                }
            }
        }
        if (hasIni) round--;
        while (!pq.empty()){
            int sz = pq.size();
            round++;
            for (int i = 0; i < sz; i++){
                int x = pq.front().first;
                int y = pq.front().second;
                pq.pop();
                for (pair<int, int> adj : adjacent){
                    int newx = x + adj.first;
                    int newy = y + adj.second;
                    if (newx < m && newx >= 0 && newy < n && newy >= 0 && grid[newx][newy] == 1){
                        pq.push({newx, newy});
                        grid[newx][newy] = -1;
                    }
                }
            }
        }
        if (checkFresh(grid)) return -1;
        return round;
    }

    bool checkFresh(vector<vector<int>>& grid){
        for (int x = 0; x < grid.size(); x++){
            for (int y = 0; y < grid[0].size(); y++){
                if (grid[x][y] == 1) return true;
            }
        }
        return false;
    }
};
