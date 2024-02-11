class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
       int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, 0)));
    
    for (int i = rows - 1; i >= 0; --i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                int currentCherries = 0;
                currentCherries += grid[i][j];
                if (j != k) {
                    currentCherries += grid[i][k];
                }
                if (i != rows - 1) {
                    int maxCherries = 0;
                    for (int dj = -1; dj <= 1; ++dj) {
                        for (int dk = -1; dk <= 1; ++dk) {
                            int nj = j + dj;
                            int nk = k + dk;
                            if (nj >= 0 && nj < cols && nk >= 0 && nk < cols) {
                                maxCherries = max(maxCherries, dp[i + 1][nj][nk]);
                            }
                        }
                    }
                    currentCherries += maxCherries;
                }
                dp[i][j][k] = currentCherries;
            }
        }
    }
    
    return dp[0][0][cols - 1];  
    }
};