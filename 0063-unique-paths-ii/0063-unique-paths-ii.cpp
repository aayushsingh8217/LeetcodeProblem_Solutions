class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
         int m = grid.size();
    int n = grid[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    dp[0][0] = (grid[0][0] == 0) ? 1 : 0;

    for (int i = 1; i < m; ++i) {
        if (grid[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int j = 1; j < n; ++j) {
        if (grid[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
    }
};