class Solution {
public:
    bool isMatch(string s, string p) {
        // int n=s.size();
        // int m=p.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        //         {
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else
        //             dp[i][j]=max(dp[i-1][j],dp[i][j]);
        //     }
        // }
        // int star=0,ques=0;
        // for(int i=0;i<m;i++)
        // {
        //     if(p[i]=='*')
        //         star++;
        //     else if(p[i]=='?')
        //         ques++;
        // }
        // if(dp[n][m]==n)
        //     return true;
        // else if(dp[n][m]<n && star>0)
        //     return true;
        // else if(n-dp[n][m]==ques)
        //     return true;
        // else
        //     return false;
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        dp[0][0] = 1; 
        for (int j = 1; j <= m && p[j - 1] == '*'; j++) {
            dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
        
    }
};