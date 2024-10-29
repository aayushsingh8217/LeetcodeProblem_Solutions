class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;
        else if(nums.size()==2 && nums[0]>nums[1])
        return 0;
        else if(nums.size()==2 && nums[0]<nums[1])
        return 1;

        int start=0,end=n-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(mid>0  && mid<n-1 )
            {
                if(nums[mid]>nums[mid+1] && nums[mid] > nums[mid-1])
                return mid;

                else if(nums[mid-1]>nums[mid])
                end=mid-1;

                else 
                start=mid+1;
            }
            else if(mid==0)
            {
                if(nums[0]>nums[1])
                return 0;
                else
                return 1;
            }

            else if(mid==n-1)
            {
                if(nums[n-1]>nums[n-2])
                return n-1;
                else 
                return n-2;
            }
        }
        return -1;
        
    }
};