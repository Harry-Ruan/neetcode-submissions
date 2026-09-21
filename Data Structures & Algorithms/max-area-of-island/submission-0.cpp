class Solution {
public:
    int maximum = 0;
    set<vector<int>> visited;
    vector<pair<int, int>> adjacent = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int x = 0; x < grid.size(); x++){
            for (int y = 0; y < grid[0].size(); y++){
                if (grid[x][y]) bfs({x,y}, grid);
            }
        }
        return maximum;
    }

    void bfs(vector<int> start, vector<vector<int>>& grid){
        int cnt = 1;
        queue<vector<int>> pq;
        pq.push({start[0], start[1]});
        visited.insert(start);
        while (!pq.empty()){
            int x = pq.front()[0];
            int y = pq.front()[1];
            pq.pop();
            for (pair<int, int> p : adjacent){
                int i = p.first;
                int j = p.second;
                if ((x + i >= 0 && x + i < grid.size()) && (y + j >= 0 && y + j < grid[0].size()) && grid[x+i][y+j] && !visited.count({x+i, y+j})){
                        cnt++;
                        pq.push({x+i, y+j});
                        visited.insert({x+i, y+j});
                    }
            }
        }
        maximum = max(cnt, maximum);
    }
};
