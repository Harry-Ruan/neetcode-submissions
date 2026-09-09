class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return true;
        if (edges.size() != n - 1) return false;
        unordered_set<int> visited;
        unordered_map<int, unordered_set<int>> childrenmp;
        for (vector<int> e : edges){
            childrenmp[e[0]].insert(e[1]);
            childrenmp[e[1]].insert(e[0]);
        }
        int start = 0;
        if (dfs(-1, 0, childrenmp, visited) && visited.size() == n) return true;
        return false;
    }

    bool dfs(int pre, int idx, unordered_map<int, unordered_set<int>>& childrenmp, unordered_set<int>& visited){
        visited.insert(idx);
        if (childrenmp[idx].empty()) return false;
        for (int child : childrenmp[idx]){
            if (child == pre) continue;
            else if (visited.count(child)) return false;
            if (!dfs(idx, child, childrenmp, visited)) return false;
        }
        return true;
    }
};
