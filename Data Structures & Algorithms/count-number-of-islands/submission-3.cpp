class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int x = 0; x < grid.size(); x++){
            for (int y = 0; y < grid[0].size(); y++){
                if (grid[x][y] == '1'){
                    BFS(x, y, grid);
                    num++;
                }
            }
        }
        return num;
    }

    void BFS(int x, int y, vector<vector<char>>& grid){
        queue<vector<int>> pq;
        pq.push({x, y});
        grid[x][y] = '#';
        while(!pq.empty()){
            int sz = pq.size();
            for (int i = 0; i < sz; i++){
                vector<int> cur = pq.front();
                pq.pop();
                vector<vector<int>> valid = adjacent(grid, cur);
                for (vector<int> v : valid){
                    pq.push(v);
                }
            }
        }
    }

    vector<vector<int>> adjacent(vector<vector<char>>& grid, vector<int>& cur){
        vector<vector<int>> res;
        int x = cur[0];
        int y = cur[1];
        if (x+1<grid.size() && grid[x+1][y] == '1' ){
            res.push_back({x+1, y});
            grid[x+1][y] = '#';
        }
        if (x-1>=0 && grid[x-1][y] == '1')
        {
            res.push_back({x-1, y});
            grid[x-1][y] = '#';
        }
        if (y+1<grid[0].size() && grid[x][y+1] == '1')
        {
            res.push_back({x, y+1});
            grid[x][y+1] = '#';
        }
        if (y-1>=0 && grid[x][y-1] == '1')
        {
            res.push_back({x, y-1});
            grid[x][y-1] = '#';
        }
        return res;
    }
};
