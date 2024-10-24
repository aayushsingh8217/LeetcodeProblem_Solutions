class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //  next_permutation(nums.begin(),nums.end());

        int n=nums.size();
        int idx=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                idx=i-1;
                break;
            }
        }
        if(idx!=-1)
        {
        int sidx=idx;
        for(int i=n-1;i>=idx+1;i--)
        {
            if(nums[i]>nums[idx])
            {
                sidx=i;
                break;
            }
        }
        swap(nums[idx],nums[sidx]);
        reverse(nums.begin()+idx+1,nums.end());
        }
        else
        {
            reverse(nums.begin(),nums.end());
        }
    }
};