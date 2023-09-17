class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         int rows = heights.size();
        int cols = heights[0].size();
        
        
        int left = 0, right = 1e6;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canReach(heights, rows, cols, mid)) {
                
                right = mid;
            } else {
                
                left = mid + 1;
            }
        }
        
        return left;
    }
      bool canReach(vector<vector<int>>& heights, int rows, int cols, int effort) {
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            if (x == rows - 1 && y == cols - 1) {
                return true; 
            }
            
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                    !visited[newX][newY] &&
                    abs(heights[x][y] - heights[newX][newY]) <= effort) {
                    
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        
        return false; 
      }
};