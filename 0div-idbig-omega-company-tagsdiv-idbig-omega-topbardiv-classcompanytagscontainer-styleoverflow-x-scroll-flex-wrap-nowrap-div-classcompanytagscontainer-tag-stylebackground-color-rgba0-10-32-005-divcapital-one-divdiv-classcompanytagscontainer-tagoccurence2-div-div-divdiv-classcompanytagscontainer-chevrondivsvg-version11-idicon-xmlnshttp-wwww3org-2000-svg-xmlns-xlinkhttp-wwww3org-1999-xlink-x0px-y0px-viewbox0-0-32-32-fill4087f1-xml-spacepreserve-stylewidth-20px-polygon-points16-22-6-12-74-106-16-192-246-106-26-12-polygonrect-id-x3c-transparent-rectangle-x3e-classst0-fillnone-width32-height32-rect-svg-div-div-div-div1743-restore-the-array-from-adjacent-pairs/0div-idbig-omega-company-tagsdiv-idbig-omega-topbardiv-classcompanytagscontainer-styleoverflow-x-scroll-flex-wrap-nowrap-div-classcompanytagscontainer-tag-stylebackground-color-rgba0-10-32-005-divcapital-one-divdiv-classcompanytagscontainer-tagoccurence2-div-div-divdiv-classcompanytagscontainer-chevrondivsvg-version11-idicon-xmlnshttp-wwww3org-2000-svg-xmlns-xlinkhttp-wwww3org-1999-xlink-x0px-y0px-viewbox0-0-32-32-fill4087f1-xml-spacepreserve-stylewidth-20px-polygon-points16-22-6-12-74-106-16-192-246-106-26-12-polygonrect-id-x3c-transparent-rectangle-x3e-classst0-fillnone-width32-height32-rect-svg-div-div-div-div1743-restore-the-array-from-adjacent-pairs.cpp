class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
      unordered_map<int, vector<int>> graph;

    for (const auto& pair : adjacentPairs) {
        graph[pair[0]].push_back(pair[1]);
        graph[pair[1]].push_back(pair[0]);
    }

    int start = 0;
    for (const auto& entry : graph) {
        if (entry.second.size() == 1) {
            start = entry.first;
            break;
        }
    }

    vector<int> result;
    unordered_set<int> visited;

    dfs(start, graph, visited, result);

    return result;   
    }
    void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, vector<int>& result) {
    visited.insert(node);
    result.push_back(node);

    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited, result);
        }
    }
    }
};