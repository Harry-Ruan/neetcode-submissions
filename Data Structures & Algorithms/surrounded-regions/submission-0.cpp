class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        for (int x = 0; x < board.size(); x++){
            for (int y = 0; y < board[0].size(); y++){
                if (board[x][y] == 'O' && !visited[x][y]){
                    vector<pair<int, int>> res = bfs(board, visited, x, y);
                    if (!res.empty()){
                            for (pair<int, int> p : res){
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }

    vector<pair<int, int>> bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y){
        vector<pair<int, int>> res;
        vector<pair<int, int>> adjacent = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int, int>> pq;
        res.push_back({x, y});
        pq.push({x, y});
        visited[x][y] = true;
        bool fail = false;
        while (!pq.empty()){
            int curx = pq.front().first;
            int cury = pq.front().second;
            pq.pop();
            for (pair<int, int> adj : adjacent){
                int newx = curx + adj.first;
                int newy = cury + adj.second;
                if (newx < 0 || newx >= board.size() || newy < 0 || newy >= board[0].size()){
                    fail = true;
                    continue;
                }
                if (board[newx][newy] == 'O' && !visited[newx][newy]){
                    pq.push({newx, newy});
                    visited[newx][newy] = true;
                    res.push_back({newx, newy});
                }
            }
        }
        if (fail) return {};
        else return res;
    }
};
