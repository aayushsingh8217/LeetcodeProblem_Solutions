class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n = nums.size();
    if (n == 0) return {};
    
    sort(nums.begin(), nums.end());
    
    vector<int> dp(n, 1), parent(n, -1);
    int maxLen = 1, maxIdx = 0;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                    maxIdx = i;
                }
            }
        }
    }
    
    vector<int> answer;
    while (maxIdx != -1) {
        answer.push_back(nums[maxIdx]);
        maxIdx = parent[maxIdx];
    }
    return answer;   
    }
};