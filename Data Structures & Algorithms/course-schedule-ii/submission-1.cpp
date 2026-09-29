class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> pq;
        vector<int> res;
        unordered_map<int, vector<int>> prereq;
        unordered_map<int, int> edges;
        int visited = 0;
        for (int i = 0; i < numCourses; i++){
            edges[i] = 0;
            prereq[i] = {};
        }
        for (vector<int> v : prerequisites){
            prereq[v[1]].push_back(v[0]);
            edges[v[0]]++;
        }
        for (auto& p : edges){
            if (!p.second){
                pq.push(p.first);
                visited++;
            }
        }
        while (!pq.empty()){
            int cur = pq.front();
            res.push_back(cur);
            pq.pop();
            for (int next : prereq[cur]){
                edges[next]--;
                if (edges[next] == 0){
                    visited++;
                    pq.push(next);
                }
            }
        }
        if (visited < numCourses) return {};
        return res;
    }
};
