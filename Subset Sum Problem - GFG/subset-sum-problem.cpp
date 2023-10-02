//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector <vector<bool>> dp(n+1,vector <bool>(sum+1,false)); 
        // return func(arr,sum,n,dp);
        
       for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                dp[i][j]=(dp[i-1][j-arr[i-1]]) || (dp[i-1][j]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
        
    }
    
    //memoise the recursion
    // bool func(vector <int> arr,int sum ,int n, vector <vector<bool>> &dp)
    // {
    //     if(sum>0 && n==0)
    //     return false;
    //     if(sum==0)
    //     return true;
        
    //     if(dp[n][sum]!=false)
    //     return dp[n][sum];
        
    //     if(arr[n-1]<=sum)
    //     return dp[n][sum]=(func(arr,sum-arr[n-1],n-1,dp)||func(arr,sum,n-1,dp));
    //     else
    //     return dp[n][sum]=func(arr,sum,n-1,dp);
    // }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends