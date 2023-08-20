class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
         vector<vector<int>> groupItems(m + n);
    
    // Assign items to their respective groups.
    for (int i = 0; i < n; ++i) {
        if (group[i] == -1) {
            group[i] = m++; // Create a new group for ungrouped items.
        }
        groupItems[group[i]].push_back(i);
    }
    
    vector<vector<int>> groupGraph(m + n);
    vector<int> groupIndegree(m + n);
    vector<vector<int>> itemGraph(n);
    vector<int> itemIndegree(n);
    
    // Build the group and item graphs.
    for (int i = 0; i < n; ++i) {
        int currGroup = group[i];
        for (int beforeItem : beforeItems[i]) {
            int beforeGroup = group[beforeItem];
            if (beforeGroup == currGroup) {
                itemGraph[beforeItem].push_back(i);
                itemIndegree[i]++;
            } else {
                groupGraph[beforeGroup].push_back(currGroup);
                groupIndegree[currGroup]++;
            }
        }
    }
    
    // Perform topological sorting for groups.
    vector<int> groupOrder;
    queue<int> q;
    for (int i = 0; i < m + n; ++i) {
        if (groupIndegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        groupOrder.push_back(u);
        
        for (int v : groupGraph[u]) {
            if (--groupIndegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    if (groupOrder.size() != m + n) {
        return {}; // No valid ordering exists.
    }
    
    vector<int> result;
    
    // Perform topological sorting for items within each group.
    for (int g : groupOrder) {
        if (g < m) { // Group node
            int groupIndex = g;
            vector<int>& items = groupItems[groupIndex];
            
            vector<int> itemOrder;
            for (int item : items) {
                if (itemIndegree[item] == 0) {
                    q.push(item);
                }
            }
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                itemOrder.push_back(u);
                
                for (int v : itemGraph[u]) {
                    if (--itemIndegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
            
            if (itemOrder.size() != items.size()) {
                return {}; // No valid ordering exists within this group.
            }
            
            result.insert(result.end(), itemOrder.begin(), itemOrder.end());
        }
    }
    
    return result;
        
    }
};