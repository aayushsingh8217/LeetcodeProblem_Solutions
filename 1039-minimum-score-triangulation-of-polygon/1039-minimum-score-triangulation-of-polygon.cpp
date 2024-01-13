class Solution {
public:
    int dp[51][51];
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return solve(values,1,values.size()-1);
    }
    int solve(vector<int>& values,int i,int j)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp_ans=solve(values,i,k)+solve(values,k+1,j)
                +values[i-1]*values[k]*values[j];
            mn=min(mn,temp_ans);
            
        }
        return dp[i][j]=mn;
    }
};