class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool exist = false;
        vector<pair<int, int>> allpairs;
        for (int i = 0; i < board[0].size(); i++){
            for (int j = 0; j < board.size(); j++){
                allpairs.push_back({i, j});
            }
        }
        for (pair<int, int> cur : allpairs) {
            set<pair<int, int>> visited;
            visited.insert(cur);
            string curword = "";
            curword += board[cur.second][cur.first];
            exist = (exist || backtracking(board, cur, curword, word, visited));
        }
        return exist;
    }

    bool backtracking(vector<vector<char>>& board, pair<int, int> cur, string curword, string word, set<pair<int, int>>& visited){
        bool exist = false;
        int cursz = curword.size();
        if (curword != word.substr(0, cursz)) return false;
        if (curword == word) return true;
        vector<pair<int, int>> valid = findadjacent(cur, board[0].size(), board.size());
        for (pair<int, int> v : valid){
            int x = v.first;
            int y = v.second;
            if (!visited.count(v)){
                visited.insert(v);
                curword += board[y][x];
                exist = (backtracking(board, v, curword, word, visited) || exist);
                curword = curword.substr(0, curword.size() - 1);
                visited.erase(v);
            }
        }
        return exist;
    }

    vector<pair<int, int>> findadjacent(pair<int, int> orr, int l, int w){
        vector<pair<int, int>> valid;
        int x = orr.first;
        int y = orr.second;
        if (x + 1 < l){
            valid.push_back({x + 1, y});
        }
        if (x - 1 >= 0){
            valid.push_back({x - 1, y});
        }
        if (y + 1 < w){
            valid.push_back({x, y + 1});
        }
        if (y - 1 >= 0){
            valid.push_back({x, y - 1});
        }
        return valid;
    }
};
