
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;
        unordered_map<int, bool> visited;
        for (vector<int> req : prerequisites){
            prereq[req[1]].push_back(req[0]);
        }
        for (int course = 0; course < numCourses; course++){
            if (!dfs(course, prereq, visited)) return false;
        }
        return true;
    }

    bool dfs(int curidx, unordered_map<int, vector<int>>& prereq, unordered_map<int, bool>& visited){
        if (visited.count(curidx)){
            if (visited[curidx]) return false;
            else return true;
        }
        if (prereq[curidx].empty()) return true;
        visited[curidx] = true;
        for (int nxtidx : prereq[curidx]){
            if (!dfs(nxtidx, prereq, visited)) return false;
        }
        visited[curidx] = false;
        return true;
    }
};