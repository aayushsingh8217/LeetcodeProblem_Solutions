class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int low=0,high=nums.size()-1;
      int idx=0;

      while(low<=high)  
      {
        int mid=low+(high-low)/2;
         
         if(nums[mid]<target)
         {
            idx=mid+1;
            low=mid+1;
         }

         else if(nums[mid]==target)
         {
            return mid;
         }

         else
         {
            high=mid-1;
         }

      }
      return idx;
    }
};