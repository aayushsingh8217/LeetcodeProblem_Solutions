class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));

        vector<int> dirs = {-1, 1, 0, 0};
        dp[0][startRow][startColumn] = 1;

        int paths = 0;
        for (int move = 1; move <= maxMove; ++move) {
                        for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k];
                        int y = j + dirs[3 - k]; 
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            paths = (paths + dp[move - 1][i][j]) % MOD;
                        } else {
                            dp[move][x][y] = (dp[move][x][y] + dp[move - 1][i][j]) % MOD;
                        }
                    }
                }
            }
        }

        return paths;  
    }
};