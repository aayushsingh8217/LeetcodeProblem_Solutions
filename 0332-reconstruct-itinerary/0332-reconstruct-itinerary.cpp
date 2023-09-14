class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
     unordered_map<string, vector<string>> graph;

    for (const auto& ticket : tickets) {
        graph[ticket[0]].push_back(ticket[1]);
    }

    for (auto& entry : graph) {
        sort(entry.second.begin(), entry.second.end(), greater<string>());
    }

    vector<string> result;

    string start = "JFK";
    dfs(graph, start, result);

    reverse(result.begin(), result.end());

    return result;   
    }
    void dfs(unordered_map<string, vector<string>>& graph, string& current, vector<string>& result) {
    while (!graph[current].empty()) {
        string next = graph[current].back();
        graph[current].pop_back();
        dfs(graph, next, result);
    }
    result.push_back(current);
    }
};