class Solution {
public:
    int mod=1e9+7;
    int a=0,e=1,i=2,o=3,u=4;
    int countVowelPermutation(int n) {
        if(n==1)
            return 5;
        else
        {
            vector <vector<long long>> dp(5,vector<long long>(n+1,0));
            long long res=0;
            for(int j=0;j<=4;j++)
            {
                dp[j][1]=1;
            }
            for(int j=2;j<=n;j++)
            {
                dp[a][j]=(dp[e][j-1]+dp[i][j-1]+dp[u][j-1])%mod;
                dp[e][j]=(dp[a][j-1]+dp[i][j-1])%mod;
                dp[i][j]=(dp[o][j-1]+dp[e][j-1])%mod;
                dp[o][j]=(dp[i][j-1])%mod;
                dp[u][j]=(dp[i][j-1]+dp[o][j-1])%mod;
                
            }
             for(int j = 0; j <= 4; j++) {
            res= (res + dp[j][n]) % mod;
        }
        return res;
        }
        
    }
};