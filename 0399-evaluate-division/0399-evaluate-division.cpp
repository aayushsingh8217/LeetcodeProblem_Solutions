class Solution {
public:
//pairs diya hai toh grpah maybe?

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

    //ek directed graph bana diya
    //har ek variable ek node hai
    //aur value between two variable ek edge
    for (int i = 0; i < equations.size(); i++) {
        const string& A = equations[i][0];
        const string& B = equations[i][1];
        double value = values[i];

        // Add A/B = value to the graph
        graph[A][B] = value;

        // Add B/A = 1/value to the graph
        graph[B][A] = 1.0 / value;
    }

    vector<double> results;

    // Evaluate each query using DFS
    for (const auto& query : queries) {
        const string& C = query[0];
        const string& D = query[1];

        // Perform DFS to find the result of C/D
        unordered_set<string> visited;
        double result = dfs(C, D, graph, visited);

        results.push_back(result);
    }

    return results; 
    }
    //DFS likhna pdeaga
    double dfs(const string& start, const string& end, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
    // If the variables are not present in the graph, return -1.0
    if (!graph.count(start) || !graph.count(end))
        return -1.0;

    // If start and end are the same variable, return 1.0
    if (start == end)
        return 1.0;

    visited.insert(start);

    // Iterate through the neighbors of the current variable
    for (const auto& neighbor : graph[start]) {
        const string& nextVar = neighbor.first;
        double weight = neighbor.second;

        // If the neighbor is not visited, perform DFS on it
        if (!visited.count(nextVar)) {
            double result = dfs(nextVar, end, graph, visited);
            
            // If a valid result is found in the DFS, return the product of weights
            if (result != -1.0)
                return weight * result;
        }
    }

    // If no valid result is found, return -1.0
    return -1;
}


};