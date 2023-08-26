class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
     int n = pairs.size();
    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1]; // Sort by the end of the interval
    });

    vector<int> dp(n, 1); // Initialize dp array with 1s
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pairs[i][0] > pairs[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());   
    }
};