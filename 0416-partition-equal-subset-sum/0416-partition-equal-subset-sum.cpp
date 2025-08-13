class Solution {
public:
    bool solve(vector<int>& nums,int sum,int n, vector<vector<int>>& dp)
    {
        if(n==0 && sum!=0)
        return false;
        if(sum==0)
        return true;

        if(dp[n][sum]!=-1)
        return dp[n][sum];

        //agar current element is gerater than sum
        if(nums[n-1]>sum)
        return dp[n][sum] = solve(nums,sum,n-1,dp);

        bool inc = solve(nums,sum-nums[n-1],n-1,dp);
        bool exc = solve(nums,sum,n-1,dp);

        return dp[n][sum]=(inc || exc);
    }
    bool canPartition(vector<int>& nums) {
      int n = nums.size() ;
      int sum=0;
      for(int i=0;i<n;i++)
      {
        sum+=nums[i];
      }
      if(sum%2!=0)
      return false;
      else{ 
        vector<vector<int>> dp(n+1,vector<int> (sum/2+1,-1));
        // -1 unassigned 0 false 1 true
      return solve(nums,sum/2,n,dp); 
      }
    }
};