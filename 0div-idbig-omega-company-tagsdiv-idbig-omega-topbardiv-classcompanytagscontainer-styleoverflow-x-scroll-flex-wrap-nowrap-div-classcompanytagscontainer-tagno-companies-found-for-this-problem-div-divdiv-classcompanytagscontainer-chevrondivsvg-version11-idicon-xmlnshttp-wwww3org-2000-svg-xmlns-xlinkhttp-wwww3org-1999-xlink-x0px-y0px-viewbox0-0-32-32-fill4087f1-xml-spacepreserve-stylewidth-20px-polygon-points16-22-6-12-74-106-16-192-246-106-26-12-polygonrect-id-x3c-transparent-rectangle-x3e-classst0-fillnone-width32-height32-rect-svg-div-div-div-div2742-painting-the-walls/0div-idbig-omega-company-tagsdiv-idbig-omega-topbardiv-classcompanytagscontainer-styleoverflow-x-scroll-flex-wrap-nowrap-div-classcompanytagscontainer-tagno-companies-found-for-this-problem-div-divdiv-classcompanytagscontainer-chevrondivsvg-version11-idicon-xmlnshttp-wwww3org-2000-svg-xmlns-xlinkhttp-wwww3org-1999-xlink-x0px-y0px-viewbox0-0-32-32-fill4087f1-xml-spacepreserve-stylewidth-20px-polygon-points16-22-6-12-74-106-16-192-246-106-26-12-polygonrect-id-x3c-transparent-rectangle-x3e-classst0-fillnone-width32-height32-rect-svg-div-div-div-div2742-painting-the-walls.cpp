class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
     const long long MOD = 500000000;
        int n = cost.size();
        vector<long long> dp(n + 1, MOD);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int walls = n; walls >= 1; walls--) {
               dp[walls] = min(dp[walls], dp[max(walls - time[i] - 1, 0)] + cost[i]);

            }
        }

        return static_cast<int>(dp[n]);
    }
};