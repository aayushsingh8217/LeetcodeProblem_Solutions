class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int mx1=1,mx2=1;
        int n=nums.size();
        mx1=(nums[0]*nums[1]*nums[n-1]);
        mx2=(nums[n-1]*nums[n-2]*nums[n-3]);
        return max(mx1,mx2);
           
    }
};