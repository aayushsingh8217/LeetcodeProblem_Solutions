class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0,cc=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            cc++;
            else
            cc=0;

            mx=max(mx,cc);
        }

        return mx;

    }
};