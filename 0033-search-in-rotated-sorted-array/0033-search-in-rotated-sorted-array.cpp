class Solution {
public:
    int search(vector<int>& nums, int target) {
  int n = nums.size();
        int idx = findMin(nums);
        int BS1 = binarySearch(nums ,  0, idx - 1,target);
        int BS2 = binarySearch(nums , idx, n-1,target);
        if(BS1 == -1)
            return BS2;
        else
            return BS1;
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int middle = left + (right - left) / 2;
            
            if (nums[middle] == target)
                return middle;
            else if (target > nums[middle])
                left = middle + 1;
            else
                right = middle - 1;
        }
        
        return -1;
    }
     int findMin(vector<int>& nums) 
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
