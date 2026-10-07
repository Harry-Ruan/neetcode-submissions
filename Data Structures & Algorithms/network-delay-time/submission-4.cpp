class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_set<int> visited;
        for (vector<int> v : times){
            if (!adj.count(v[0])) adj[v[0]] = {};
            adj[v[0]].push_back({v[1], v[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            visited.insert(u);
            if (d > dist[u]) continue;
            for (const auto& [v, w] : adj[u]){
                if (dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maximum = 0;
        for (int i = 0; i < n + 1; i++){
            maximum = max(maximum, dist[i]);
        }
        return visited.size() == n ? maximum : -1;
    }
}; 

// compare distto value, not single weight!!!
