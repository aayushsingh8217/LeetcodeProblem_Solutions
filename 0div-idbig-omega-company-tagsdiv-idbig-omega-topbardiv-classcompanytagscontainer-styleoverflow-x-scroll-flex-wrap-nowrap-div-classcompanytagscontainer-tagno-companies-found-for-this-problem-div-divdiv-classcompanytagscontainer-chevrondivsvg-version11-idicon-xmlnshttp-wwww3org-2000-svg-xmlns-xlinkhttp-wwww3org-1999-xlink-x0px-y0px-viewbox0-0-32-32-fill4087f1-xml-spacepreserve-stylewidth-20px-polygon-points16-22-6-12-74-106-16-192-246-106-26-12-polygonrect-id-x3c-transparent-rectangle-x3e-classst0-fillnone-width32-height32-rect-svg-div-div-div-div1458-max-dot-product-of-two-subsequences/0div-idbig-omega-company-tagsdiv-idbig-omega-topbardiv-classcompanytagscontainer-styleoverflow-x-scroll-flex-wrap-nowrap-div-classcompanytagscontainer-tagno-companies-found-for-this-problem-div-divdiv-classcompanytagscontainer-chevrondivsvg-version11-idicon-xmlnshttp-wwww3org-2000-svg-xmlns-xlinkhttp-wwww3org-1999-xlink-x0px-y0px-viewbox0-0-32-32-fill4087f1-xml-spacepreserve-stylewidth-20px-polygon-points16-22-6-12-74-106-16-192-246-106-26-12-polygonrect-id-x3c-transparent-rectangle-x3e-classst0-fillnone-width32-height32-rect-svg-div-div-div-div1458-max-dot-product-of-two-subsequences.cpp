class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
     int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

    
    dp[0][0] = nums1[0] * nums2[0];

    
    for (int j = 1; j < n; ++j) {
        dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);
    }

    
    for (int i = 1; i < m; ++i) {
        dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
    }

    
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = max({
                dp[i - 1][j - 1] + nums1[i] * nums2[j],
                dp[i - 1][j],
                dp[i][j - 1],
                nums1[i] * nums2[j]
            });
        }
    }

    return dp[m - 1][n - 1];    
    }
};