class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int res = -1;
      int s = 0, e= nums.size()-1;
      while(s <= e)
      {
        int m = s+(e-s)/2;
        if(nums[m] > target)
        e = m-1;
        else if(nums[m]< target)
        {
            res = m;
            s = m+1;
        }
        else if(nums[m] == target)
        return m;
      }
       return res+1;  
    }
};