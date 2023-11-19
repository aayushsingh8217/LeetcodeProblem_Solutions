class Solution {
public:
    int reductionOperations(vector<int>& nums) {
     sort(nums.begin(), nums.end());
        int result = 0;
        int curr = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                curr += 1;
            }
            result += curr;
        }

        return result;   
    }
};