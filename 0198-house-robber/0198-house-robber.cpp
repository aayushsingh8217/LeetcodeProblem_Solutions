class Solution {
public:
    int rob(vector<int>& nums) {
        // int sum1=0;int sum2=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(i%2==0)
        //     sum1+=nums[i];
        //     else
        //     sum2+=nums[i];
        // }
        // return max(sum1,sum2);
        int l=nums.size();
        vector <int> dp(l+1,0);
        if(l==1)
        return nums[0];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=l;i++)
        {
            int stolen=nums[i-1]+dp[i-2];
            int leftalone=dp[i-1];
            dp[i]=max(stolen,leftalone);
        }
        return dp[l];
        
    }
};