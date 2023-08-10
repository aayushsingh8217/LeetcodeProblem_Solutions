class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
    int right = nums.size()-1 ;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }

        // Check which side is sorted and perform binary search accordingly
        if (nums[left] < nums[mid]) {
            // Left half is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (nums[left] > nums[mid]) {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            // Duplicates found, move left pointer
            left++;
        }
    }

    return false;   
    }
};