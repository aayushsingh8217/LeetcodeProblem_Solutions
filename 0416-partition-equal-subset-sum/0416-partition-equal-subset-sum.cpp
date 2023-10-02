class Solution {
public:
    bool canPartition(vector<int>& nums) {
     int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        else
        {
            vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));
            return func(nums,n,dp,int (sum/2));
            }
    }
    bool func(vector <int> &nums,int n, vector <vector<bool>> &dp,int sum)
    {
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                  if(nums[i-1]<=j)
         dp[i][j]=(dp[i-1][j-nums[i-1]])||(dp[i-1][j]);
        else
         dp[i][j]=(dp[i-1][j]);
            }
        }
        
        
//         if(sum>0 && n==0)
//         return false;
//         if(sum==0)
//         return true;
        
//         if(dp[n][sum]!=false)
//         return dp[n][sum];
        
//         if(nums[n-1]<=sum)
//         return dp[n][sum]=(func(nums,n-1,dp,sum-nums[n-1])||func(nums,n-1,dp,sum));
//         else
//         return dp[n][sum]=func(nums,n-1,dp,sum);
    return dp[n][sum];
    }
};