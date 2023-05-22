class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int k=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[k]!=nums[i])
            {
                k++;
                nums[k]=nums[i];
            }
        }
        return k+1;
    }
};