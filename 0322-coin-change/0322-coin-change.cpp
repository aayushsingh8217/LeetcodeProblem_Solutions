class Solution {
public:
    int solve(vector<int>& coins,int s,int i,vector<vector<int>>& dp)
    {
        if(s==0)
        return 0;
        if(s<0 || i<=0)
        return 1e7;

        if(dp[i][s]!=-1)
        return dp[i][s];

        int include = 1 + solve(coins,s-coins[i-1],i,dp);
        int exclude = solve(coins,s,i-1,dp);

        return dp[i][s]=min(include,exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int res = solve(coins,amount,n,dp);
        return (res>=1e7)?-1:res;
    }
};