class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        struct Cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second > b.second;
        }
    };
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_set<int> visited;
        int sum = 0;
        for (int start = 0; start < points.size(); start++){
            for(int end = 0; end < points.size(); end++){
                vector<int> src = points[start];
                vector<int> dst = points[end];
                if (!adj.count(start)) adj[start] = {};
                adj[start].push_back({end, abs(src[0] - dst[0]) + abs(src[1] - dst[1])});
            }
        }
        for (pair<int, int> p : adj[0]){
            pq.push(p);
        }
        visited.insert(0);
        while (!pq.empty() && visited.size() < points.size()){
            int next = pq.top().first;
            int w = pq.top().second;
            pq.pop();
            if (visited.count(next)) continue;
            sum += w;
            visited.insert(next);
            for (pair<int, int> p : adj[next]){
                if (!visited.count(p.first)){
                    pq.push(p);
                }
            }
        }
        return sum;
    }
};
