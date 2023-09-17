class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
         int n = graph.size();
        

        vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));
        
        
        queue<tuple<int, int, int>> q;
        
       
        for (int i = 0; i < n; i++) {
            dp[i][1 << i] = 0;
            q.push({i, 1 << i, 0});
        }
        
        while (!q.empty()) {
            auto [curNode, mask, distance] = q.front();
            q.pop();
            
            if (mask == (1 << n) - 1) {
                
                return distance;
            }
            
            for (int neighbor : graph[curNode]) {
                int newMask = mask | (1 << neighbor);
                if (distance + 1 < dp[neighbor][newMask]) {
                    dp[neighbor][newMask] = distance + 1;
                    q.push({neighbor, newMask, distance + 1});
                }
            }
        }
        
        return -1; 
    }
};