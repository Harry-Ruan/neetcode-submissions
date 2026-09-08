class DSU{
public:
    vector<int> parent, size;
    int cmpt;

    DSU(int n){
        cmpt = n;
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int cur){
        if (parent[cur] != cur) {
            parent[cur] = find(parent[cur]);
        }
        return parent[cur];
    }

    bool tounion(int x, int y){
        int xp = find(x);
        int yp = find(y);
        if (xp == yp) return false;
        if (size[xp] > size[yp]){
            swap(xp, yp);
        }
        parent[xp] = yp;
        size[yp] += size[xp];
        cmpt--;
        return true;
    }

    int components(){
        return cmpt;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n); 
        for (vector<int> v : edges){
            dsu.tounion(v[0], v[1]);
        }
        int res = dsu.components();
        return res;
    }
};
