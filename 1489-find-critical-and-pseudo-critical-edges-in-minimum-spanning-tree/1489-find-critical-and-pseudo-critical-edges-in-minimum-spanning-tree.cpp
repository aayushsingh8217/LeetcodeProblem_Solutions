class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
         int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);  
        }
        
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];  
        });
        
        int mstWeight = kruskal(n, edges, -1, -1);  
        vector<vector<int>> result(2);  
        
        for (int i = 0; i < m; ++i) {
            int weightWithout = kruskal(n, edges, -1, i);  
            
            if (weightWithout > mstWeight) {
                result[0].push_back(edges[i][3]);  
            } else {
                int weightWith = kruskal(n, edges, i, -1);  
                
                if (weightWith == mstWeight) {
                    result[1].push_back(edges[i][3]);  
                }
            }
        }
        
        return result;
    }
    private:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    int kruskal(int n, const vector<vector<int>>& edges, int include, int exclude) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        int totalWeight = 0;
        if (include != -1) {
            totalWeight += edges[include][2];
            parent[find(edges[include][0])] = find(edges[include][1]);
        }
        
        for (int i = 0; i < edges.size(); ++i) {
            if (i == exclude) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            if (find(u) != find(v)) {
                parent[find(u)] = find(v);
                totalWeight += weight;
            }
        }
        
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                components++;
            }
        }
        
        return (components == 1) ? totalWeight : INT_MAX;
    }
};