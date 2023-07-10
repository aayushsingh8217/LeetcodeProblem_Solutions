class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int idx;
        if(nums.size()<1)
        {
            return 0;
        }
        else
        {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<target)
            {
                idx=mid+1;
                start=mid+1;
            }
            else if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
        }
        }
        return idx;
    }
};