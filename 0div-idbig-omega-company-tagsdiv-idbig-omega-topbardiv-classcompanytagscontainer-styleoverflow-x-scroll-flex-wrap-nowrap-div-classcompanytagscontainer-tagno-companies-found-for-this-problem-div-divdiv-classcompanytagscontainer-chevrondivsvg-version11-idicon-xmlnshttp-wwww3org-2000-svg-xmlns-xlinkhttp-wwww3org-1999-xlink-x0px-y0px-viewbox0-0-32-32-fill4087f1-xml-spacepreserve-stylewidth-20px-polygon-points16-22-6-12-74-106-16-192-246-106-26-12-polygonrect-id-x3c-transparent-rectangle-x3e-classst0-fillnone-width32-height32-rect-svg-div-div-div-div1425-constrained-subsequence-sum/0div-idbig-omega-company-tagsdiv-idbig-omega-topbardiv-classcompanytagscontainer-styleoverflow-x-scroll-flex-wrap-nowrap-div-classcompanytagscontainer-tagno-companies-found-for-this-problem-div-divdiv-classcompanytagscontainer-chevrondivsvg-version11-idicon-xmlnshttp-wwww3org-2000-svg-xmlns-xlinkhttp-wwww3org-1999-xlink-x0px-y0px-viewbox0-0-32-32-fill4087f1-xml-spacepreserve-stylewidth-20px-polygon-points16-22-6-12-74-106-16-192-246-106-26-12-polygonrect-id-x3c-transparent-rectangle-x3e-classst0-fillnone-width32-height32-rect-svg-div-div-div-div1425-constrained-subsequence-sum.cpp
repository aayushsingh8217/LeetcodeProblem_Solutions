class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
  int n = nums.size();
    vector<int> dp(n, 0);
        int ans = INT_MIN;
        std::deque<int> q;

        for (int i = 0; i < n; i++) {
            if (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            dp[i] = std::max(0, q.empty() ? 0 : dp[q.front()]) + nums[i];

            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};