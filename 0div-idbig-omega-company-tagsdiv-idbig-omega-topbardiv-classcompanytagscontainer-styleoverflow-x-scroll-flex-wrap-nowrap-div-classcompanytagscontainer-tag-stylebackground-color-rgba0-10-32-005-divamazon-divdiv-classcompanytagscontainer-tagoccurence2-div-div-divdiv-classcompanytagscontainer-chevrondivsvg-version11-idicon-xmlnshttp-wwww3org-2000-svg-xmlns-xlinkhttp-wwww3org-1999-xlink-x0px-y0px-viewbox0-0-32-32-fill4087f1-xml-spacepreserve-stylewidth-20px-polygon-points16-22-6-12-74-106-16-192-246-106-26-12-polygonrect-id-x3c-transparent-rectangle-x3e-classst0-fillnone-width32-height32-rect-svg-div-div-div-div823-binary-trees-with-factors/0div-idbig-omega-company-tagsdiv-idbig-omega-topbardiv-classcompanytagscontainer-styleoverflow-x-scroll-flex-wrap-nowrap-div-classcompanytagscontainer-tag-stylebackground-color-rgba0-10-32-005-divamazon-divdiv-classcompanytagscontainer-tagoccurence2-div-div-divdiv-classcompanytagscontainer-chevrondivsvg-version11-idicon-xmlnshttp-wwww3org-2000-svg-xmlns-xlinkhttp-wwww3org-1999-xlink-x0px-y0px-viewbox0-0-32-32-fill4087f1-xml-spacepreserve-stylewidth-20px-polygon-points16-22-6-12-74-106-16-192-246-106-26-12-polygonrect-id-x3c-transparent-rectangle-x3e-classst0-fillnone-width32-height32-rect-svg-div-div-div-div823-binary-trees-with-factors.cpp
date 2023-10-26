class Solution {
public:
    const int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
      int n = arr.size();
    sort(arr.begin(), arr.end());
    unordered_map<int, long> dp;
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[arr[i]] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] % arr[j] == 0) {
                int div = arr[i] / arr[j];
                if (dp.count(div)) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[div]) % MOD;
                }
            }
        }
        ans = (ans + dp[arr[i]]) % MOD;
    }
    
    return ans;  
    }
};