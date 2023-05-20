class Solution {
public:
//const int N = 205;
//int dp[100][100];

    int maxScore(vector<int>& nums) {
        vector<int> dp(1 << size(nums));
        for (int mask = 3; mask < size(dp); ++mask) {
            int flag = __builtin_popcount(mask);
            if (flag % 2) {
                continue;
            }
            vector<int> res;
            for (int i = 0, m = mask; m; ++i, m >>= 1) {
                if (m & 1) {
                    res.emplace_back(i);
                }
            }
            for (int i = 0; i < size(res); ++i) {
                for (int j = i + 1; j < size(res); ++j) {
                    dp[mask] = max(dp[mask], flag / 2 * gcd(nums[res[i]], nums[res[j]]) + dp[mask ^ (1 << res[i]) ^ (1 << res[j])]);
                }
            }
        }
        return dp.back();
    }
//     int gcd(int a, int b) {
//     if (b == 0) return a;
//     return gcd(b, a % b);
// }
};