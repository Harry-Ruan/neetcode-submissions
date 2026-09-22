class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int x = 0; x < grid.size(); x++){
            for (int y = 0; y < grid[0].size(); y++){
                if (grid[x][y] == 0){
                    bfs(grid, x, y);
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, int x, int y){
        int step = 0;
        queue<pair<int, int>> pq;
        vector<pair<int, int>> adjacent = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        pq.push({x, y});
        while (!pq.empty()){
            int sz = pq.size();
            step++;
            for (int i = 0; i < sz; i++){
                int curx = pq.front().first;
                int cury = pq.front().second;
                pq.pop();
                for (pair<int, int> p : adjacent){
                    int newx = curx + p.first;
                    int newy = cury + p.second;
                    if (newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size()) {
                        if (grid[newx][newy] > step){
                            pq.push({newx, newy});
                            grid[newx][newy] = step;
                        }
                        // else if (grid[newx][newy] != 0){
                            // grid[newx][newy] = min(step, grid[newx][newy]);
                        // }
                    }
                }
            }
        }
    }
};
