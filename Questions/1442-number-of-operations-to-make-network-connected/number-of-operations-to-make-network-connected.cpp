class Disjoint {
    public:
        vector<int> rank , parents , size;
        Disjoint(int n) {
            rank.resize(n+1 , 0);
            size.resize(n+1 , 0);
            parents.resize(n+1);
            for(int i=0 ; i<=n ; i++) {
                parents[i] = i;
            }
        }

        int findParent(int node) {
            if(node == parents[node]) {
                return node;
            }

            return parents[node] = findParent(parents[node]);
        }

        void unionByRank(int u , int v) {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]) {
                parents[ulp_u] = ulp_v;
            }
            else if(ulp_u > ulp_v) {
                parents[ulp_v] = ulp_u;
            }
            else {
                rank[ulp_u]++;
                parents[ulp_v] = ulp_u;
            }
        }

        void unionBySize(int u , int v) {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]) {
                parents[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parents[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int extraEdges = 0;
        for(int i=0 ; i<connections.size() ; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            if(ds.findParent(u) == ds.findParent(v)) {
                extraEdges++;
            }
            else {
                ds.unionBySize(u , v);
            }
        }

        int component = 0;
        for(int i=0 ; i<n ; i++) {
            if(ds.parents[i] == i) {
                component++;
            }
        }

        if(extraEdges >= component-1) {
            return component-1;
        }
        
        return -1;
    }
};