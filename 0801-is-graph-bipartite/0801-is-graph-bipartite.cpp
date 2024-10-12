class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int N = adj.size();
        vector<int> color(N, -1);
        for (int i = 0; i < N; i++) {
            // Only start BFS if the node is unvisited
            if (color[i] == -1) {
                if (!BFS(adj, i, color, 1)) {
                    return false;
                }
            }
        }
        return true; // All components are bipartite
    }

    bool BFS(vector<vector<int>>& adj, int u, vector<int>& color, int ccolor) {
        queue<int> q;
        q.push(u);
        color[u] = ccolor;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto& it : adj[v]) {
                // If the neighbor has the same color, it's not bipartite
                if (color[it] == color[v]) {
                    return false;
                }
                // If the neighbor hasn't been colored yet
                else if (color[it] == -1) {
                    color[it] = 1 - color[v]; // Alternate color
                    q.push(it);
                }
            }
        }
        return true; // Successfully colored this component
    }
};