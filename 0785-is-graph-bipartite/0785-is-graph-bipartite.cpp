class Solution {
public:
//Microsoft,Amazon,Flipkart,Samsung
        //length dekhna pdeaga graph ka
        // st graph bipartite ho sakta always
        // lekin odd length ka cycle graph nahi ho sakta
        //even lenght ka cyclic grpah ho skata hai
       bool isBipartiteUtil(const std::vector<std::vector<int>>& graph, int node, std::vector<int>& color) {
    for (int neighbor : graph[node]) {
        if (color[neighbor] == color[node]) {
            return false;  // Found adjacent nodes with the same color, not bipartite
        } else if (color[neighbor] == 0) {
            color[neighbor] = -color[node];  // Assign opposite color to the neighbor
            if (!isBipartiteUtil(graph, neighbor, color)) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> color(n, 0);  // 0 indicates uncolored, 1 and -1 represent two different colors

    for (int node = 0; node < n; ++node) {
        if (color[node] == 0) {
            color[node] = 1;  // Assign the first color to the initial node
            if (!isBipartiteUtil(graph, node, color)) {
                return false;
            }
        }
    }
    return true;
}
};