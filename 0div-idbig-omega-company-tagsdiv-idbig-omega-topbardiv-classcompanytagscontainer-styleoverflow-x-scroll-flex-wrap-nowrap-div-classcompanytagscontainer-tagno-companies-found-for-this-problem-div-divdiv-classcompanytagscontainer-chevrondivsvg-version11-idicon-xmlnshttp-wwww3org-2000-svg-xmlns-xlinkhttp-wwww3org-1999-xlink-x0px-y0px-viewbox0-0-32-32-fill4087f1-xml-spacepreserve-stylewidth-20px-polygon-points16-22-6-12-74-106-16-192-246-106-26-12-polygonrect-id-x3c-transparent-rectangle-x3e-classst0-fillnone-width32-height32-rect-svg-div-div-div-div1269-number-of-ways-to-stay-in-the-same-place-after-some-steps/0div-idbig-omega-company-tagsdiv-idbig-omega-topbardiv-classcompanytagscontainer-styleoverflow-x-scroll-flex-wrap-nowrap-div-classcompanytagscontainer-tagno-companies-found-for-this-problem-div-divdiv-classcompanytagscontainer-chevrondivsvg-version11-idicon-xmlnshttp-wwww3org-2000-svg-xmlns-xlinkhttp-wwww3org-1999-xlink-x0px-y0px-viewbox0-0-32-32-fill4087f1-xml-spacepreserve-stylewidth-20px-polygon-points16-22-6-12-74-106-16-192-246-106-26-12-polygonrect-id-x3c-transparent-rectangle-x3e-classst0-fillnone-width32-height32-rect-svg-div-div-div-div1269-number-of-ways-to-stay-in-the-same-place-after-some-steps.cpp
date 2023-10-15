class Solution {
public:
    int numWays(int steps, int arrLen) {
     const int MOD = 1000000007;
    int maxPos = min(steps, arrLen - 1);
    vector<vector<long long>> dp(steps + 1, vector<long long>(maxPos + 1, 0));
    
    dp[0][0] = 1;
   
    for (int i = 1; i <= steps; i++) {
        for (int j = 0; j <= maxPos; j++) {
            dp[i][j] = dp[i - 1][j];
            
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            
            if (j < maxPos) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    
    return dp[steps][0];   
    }
};