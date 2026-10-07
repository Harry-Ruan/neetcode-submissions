#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // memo[node][stops] stores the min cost from node to dst with remaining stops allowed
        vector<vector<int>> memo(n, vector<int>(k + 2, -2));

        int result = dfs(adj, src, dst, k + 1, memo);
        return result >= 1e9 ? -1 : result;
    }

    int dfs(const vector<vector<pair<int, int>>>& adj, int cur, int dst, int stopsLeft, vector<vector<int>>& memo) {
        if (cur == dst) return 0;
        if (stopsLeft == 0) return 1e9;
        if (memo[cur][stopsLeft] != -2) return memo[cur][stopsLeft];

        int minCost = 1e9;
        for (const auto& [next, price] : adj[cur]) {
            int cost = dfs(adj, next, dst, stopsLeft - 1, memo);
            if (cost != 1e9) {
                minCost = min(minCost, price + cost);
            }
        }

        return memo[cur][stopsLeft] = minCost;
    }
};