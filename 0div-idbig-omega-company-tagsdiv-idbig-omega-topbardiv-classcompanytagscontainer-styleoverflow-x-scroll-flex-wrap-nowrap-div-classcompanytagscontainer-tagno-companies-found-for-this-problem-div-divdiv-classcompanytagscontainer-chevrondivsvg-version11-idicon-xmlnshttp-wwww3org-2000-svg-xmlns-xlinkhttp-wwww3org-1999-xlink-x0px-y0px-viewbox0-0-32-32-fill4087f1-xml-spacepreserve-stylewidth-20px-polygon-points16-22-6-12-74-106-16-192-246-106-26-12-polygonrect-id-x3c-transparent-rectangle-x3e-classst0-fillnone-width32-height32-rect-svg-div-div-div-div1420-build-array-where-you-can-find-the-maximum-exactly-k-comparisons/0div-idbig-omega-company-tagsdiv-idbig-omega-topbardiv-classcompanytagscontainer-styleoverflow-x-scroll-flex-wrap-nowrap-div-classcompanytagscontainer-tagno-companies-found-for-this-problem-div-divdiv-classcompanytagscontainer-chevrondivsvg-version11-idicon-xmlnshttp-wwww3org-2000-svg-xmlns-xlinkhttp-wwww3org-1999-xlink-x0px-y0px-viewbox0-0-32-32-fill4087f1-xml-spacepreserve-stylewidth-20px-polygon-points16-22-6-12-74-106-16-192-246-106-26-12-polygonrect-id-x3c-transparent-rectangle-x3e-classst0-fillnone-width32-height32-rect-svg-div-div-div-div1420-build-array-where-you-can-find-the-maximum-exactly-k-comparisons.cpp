class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int MOD = 1000000007;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
        vector<vector<vector<int>>> predp(2, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
        for (int i = 1; i <= m; ++i) {
            dp[1][i][1] = 1;
            predp[1][i][1] = (predp[1][i - 1][1] + dp[1][i][1]) % MOD;
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= k; ++j) {
                    dp[l % 2][i][j] = (static_cast<long long>(i) * dp[(l - 1) % 2][i][j] % MOD +
                                      predp[(l - 1) % 2][i - 1][j - 1]) %
                                     MOD;
                    predp[l % 2][i][j] = (predp[l % 2][i - 1][j] + dp[l % 2][i][j]) % MOD;
                }
            }
        }

        return predp[n % 2][m][k];
    }
};