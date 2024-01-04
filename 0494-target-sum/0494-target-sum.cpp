class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target || nums[0]==-target)
                return 1;
            else
                return 0;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            }
        if((sum+target)%2==1)
            return 0;
        int zeroflag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zeroflag++;
        }
     int s1=(target+sum)/2;
        if(s1<0)
            return 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(s1+1,0));
        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<=s1;j++)
            {
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=1;j<=s1;j++)
            {
                if(nums[i-1]==0)
                    dp[i][j]=dp[i-1][j];
                else if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
            }
        }
         return pow(2, zeroflag) * dp[nums.size()][s1];
    }
};