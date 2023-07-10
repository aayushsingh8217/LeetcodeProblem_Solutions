class Solution {
public:
    int findMin(vector<int>& nums) {
        int idx=FindMin(nums);
        return nums[idx];
    }
      int FindMin(vector<int>& nums) 
    {
        int n = nums.size();
        int start = 0, end = n-1;
        if(nums[start] < nums[end])
        {
            return 0;
        }
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int next = (mid+1)%n;
            int prev = (mid + n - 1)%n;
            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev])
            {
                return mid;
            }
            if(nums[mid] <= nums[end])
            {
                end = mid - 1;
            }
            else if(nums[start] <= nums[mid])
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};
