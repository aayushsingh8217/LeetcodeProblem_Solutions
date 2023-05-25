class Solution {
public:
    double new21Game(int n, int k, int maxpoints) {
         if (k == 0 || n >= k + maxpoints) {
            return 1.0f;
        }
        vector<double> dp(n + 1);
        dp[0] = 1.0f;
        double maxpoints_sum = 1.0f, res = 0.0f;
        for (int i = 1; i <= n; ++i) {
            dp[i] = maxpoints_sum / maxpoints;
            if (i < k) {
                maxpoints_sum += dp[i];
            } else {
                res += dp[i];
            }
            if (i - maxpoints >= 0) {
                maxpoints_sum -= dp[i - maxpoints];
            }
        }
        return res;
    }
};