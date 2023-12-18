class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=nums.size();
        return ((nums[m-1]*nums[m-2])-(nums[0]*nums[1]));
    }
};