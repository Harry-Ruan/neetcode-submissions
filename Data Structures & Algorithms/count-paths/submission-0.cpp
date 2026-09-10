class Solution {
public:
    int uniquePaths(int m, int n) {
        queue<vector<int>> pq;
        set<vector<int>> added;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        pq.push({0, 0});
        grid[0][0] = 1;
        added.insert({0,0});
        while (!pq.empty()){
            int sz = pq.size();
            for (int i = 0; i < sz; i++){
                vector<int> cur = pq.front();
                pq.pop();
                int x = cur[0];
                int y = cur[1];
                if (x - 1 >= 0){
                    grid[x][y] += grid[x-1][y];
                }
                if (y - 1 >= 0){
                    grid[x][y] += grid[x][y-1];
                }
                if (x + 1 < m && !added.count({x+1, y})){
                    pq.push({x+1, y});
                    added.insert({x+1,y});
                }
                if (y + 1 < n && !added.count({x, y+1})){
                    pq.push({x, y+1});
                    added.insert({x,y+1});
                }
            }
        }
        return grid[m-1][n-1];
    }
};
