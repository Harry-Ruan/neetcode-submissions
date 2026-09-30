class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    // Unite the sets containing 'i' and 'j' using union by rank
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i == root_j)
            return false; // Already in the same set

        // Union by rank
        if (rank[root_i] < rank[root_j]) {
            parent[root_i] = root_j;
        } else if (rank[root_i] > rank[root_j]) {
            parent[root_j] = root_i;
        } else {
            parent[root_j] = root_i;
            rank[root_i]++;
        }
        return true;
    }

    // Check if 'i' and 'j' belong to the same set
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        DSU relations(2 * edges.size());
        for (vector<int> edge : edges){
            if (relations.connected(edge[0], edge[1])) return edge;
            relations.unite(edge[0], edge[1]);
        }
        return {};
    }
};

