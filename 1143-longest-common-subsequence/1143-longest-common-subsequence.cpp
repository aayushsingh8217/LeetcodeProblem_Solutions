class Solution {
public:
// int lt1,lt2;
// int dp[1001][1001];
//     int longestCommonSubsequence(string text1, string text2) {
//          lt1=text1.length();
//             lt2=text2.length();
//             memset(dp,-1,sizeof(dp));
//             return max_sub(text1,text2,0,0);
        
//     }
//     int max_sub(string &a,string &b,int i,int j)
//     {
//         if(i>=lt1 || j>=lt2)
//         return 0;
//         if(dp[i][j]!=-1)
//         return dp[i][j];
//         if(a[i]==b[j])
//         return dp[i][j]=1+max_sub(a,b,i+1,j+1);
//         return dp[i][j]=max(max_sub(a,b,i,j+1),max_sub(a,b,i+1,j));
//     }
    int dp[1001][1001];
         int longestCommonSubsequence(string text1, string text2) {
          int n=text1.size();
             int m=text2.size();
             memset(dp,-1,sizeof(dp));
             return solverecur(n,m,text1,text2);
             
        
     }
    int solverecur(int n,int m,string &text1,string &text2)
    {
        if(n==0 || m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(text1[n-1]==text2[m-1])
            return dp[n][m]=1+solverecur(n-1,m-1,text1,text2);
        else
            return dp[n][m]=max(solverecur(n-1,m,text1,text2),solverecur(n,m-1,text1,text2));
        
    }
};