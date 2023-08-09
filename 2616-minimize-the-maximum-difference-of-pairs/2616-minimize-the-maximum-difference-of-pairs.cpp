class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
    auto check = [&](int x) {
            int i = 0, cnt = 0;
            while (i + 1 < nums.size() && cnt < p) {
                if (nums[i + 1] - nums[i] <= x) {
                    i++;
                    cnt++;
                }
                i++;
            }
            return cnt == p;
        };

        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};