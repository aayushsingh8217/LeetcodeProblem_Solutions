class Solution {
public:
    int countOrders(int n) {
      const int MOD = 1000000007;
        long long result = 1;
        for (int i = 2 * n; i >= 2; i -= 2) {
            result = (result * i * (i - 1) / 2) % MOD;
        }
        return static_cast<int>(result);
    }
};