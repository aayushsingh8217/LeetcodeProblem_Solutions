class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }

        vector<long long> dp(n + 1, 0);

        dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i - 1; j++) {
                dp[i] = max(dp[i], max((long long)j * (i - j), dp[j] * (i - j)));
            }
        }

        return dp[n];
    }
};