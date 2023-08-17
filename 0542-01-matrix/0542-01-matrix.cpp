class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
    
    queue<pair<int, int>> q;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                distance[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int x = cell.first + dx[k];
            int y = cell.second + dy[k];
            
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (distance[x][y] > distance[cell.first][cell.second] + 1) {
                    distance[x][y] = distance[cell.first][cell.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    
    return distance;
    }
};