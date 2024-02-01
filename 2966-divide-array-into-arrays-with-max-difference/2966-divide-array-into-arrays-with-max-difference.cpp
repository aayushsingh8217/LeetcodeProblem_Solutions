class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    while (i < n) {
        vector<int> temp;
        temp.push_back(nums[i]);
        int j = i + 1;
        while (j < n && nums[j] - nums[i] <= k && j - i < 3) {
            temp.push_back(nums[j]);
            j++;
        }
        if (temp.size() < 3) {
            result.clear();
            break;
        }
        result.push_back(temp);
        i = j;
    }
    return result;
    }
};