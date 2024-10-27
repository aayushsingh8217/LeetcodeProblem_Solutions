class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fo=-1,lo=-1;

        int low =0,high=nums.size()-1;
        vector<int> res(2,-1);
        //fo
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                fo=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            low=mid+1;
            else
            high=mid-1;
        }

        //lo
        low=0,high=nums.size()-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(nums[mid]==target)
            {
                lo=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
            high=mid-1;
            else
            low=mid+1;
        }

        res[0]=fo;
        res[1]=lo;

        return res;
    }
};