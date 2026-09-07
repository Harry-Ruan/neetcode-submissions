class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<vector<int>> pq;
        queue<vector<int>> aq;

        // 1. 太平洋边界统一入队（左 + 上）
        for (int x = 0; x < m; x++) {
            pacific[x][0] = true;
            pq.push({x, 0});
        }
        for (int y = 0; y < n; y++) {
            pacific[0][y] = true;
            pq.push({0, y});
        }

        // 2. 大西洋边界统一入队（右 + 下）
        for (int x = 0; x < m; x++) {
            atlantic[x][n - 1] = true;
            aq.push({x, n - 1});
        }
        for (int y = 0; y < n; y++) {
            atlantic[m - 1][y] = true;
            aq.push({m - 1, y});
        }

        // 3. 两次 BFS
        bfs(heights, pq, pacific);
        bfs(heights, aq, atlantic);

        // 4. 收集重合点
        vector<vector<int>> res;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (pacific[x][y] && atlantic[x][y]) {
                    res.push_back({x, y});
                }
            }
        }
        return res;
    }

private:
    void bfs(vector<vector<int>>& heights, queue<vector<int>>& q, vector<vector<bool>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int curx = cur[0], cury = cur[1];

            for (auto& dir : dirs) {
                int nx = curx + dir[0];
                int ny = cury + dir[1];

                // 越界校验
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                // 未访问过 && 符合逆流高度要求
                if (!visited[nx][ny] && heights[nx][ny] >= heights[curx][cury]) {
                    visited[nx][ny] = true; // 正确顺序：先判断没访问过，再标记为 true 并入队
                    q.push({nx, ny});
                }
            }
        }
    }
};