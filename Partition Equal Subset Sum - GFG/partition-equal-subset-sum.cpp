//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int nums[])
    { 
    
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
            return func(nums,n,dp, int(sum/2));
            }
        
    }
    bool func(int nums[],int n, vector <vector<bool>> &dp,int sum)
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
         return dp[n][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends