class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
 int n = nums.size();
        int targetSum = 0;
        for (int num : nums) {
            targetSum += num;
        }
        
        int left = 0, right = 0;
        int currentSum = 0;
        int minOperations = INT_MAX;
        
        while (right < n) {
            currentSum += nums[right];
            right++;
            
            while (currentSum > targetSum - x && left < right) {
                currentSum -= nums[left];
                left++;
            }
            
            if (currentSum == targetSum - x) {
                minOperations = min(minOperations, n - (right - left));
            }
        }
        
        return minOperations == INT_MAX ? -1 : minOperations;
    }
};