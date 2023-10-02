//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        
        
        //Recursion ---------------------
    //   if(n==0 || w==0)
    //   return 0;
    //   if(wt[n-1]<=w)
    //   {
    //       return max(val[n-1]+knapSack(w-wt[n-1],wt,val,n-1),knapSack(w,wt,val,n-1));
    //   }
    //   else if(wt[n-1]>w)
    //   {
    //       return knapSack(w,wt,val,n-1);
    //   }
    //-------------------------------------------
    
    //Memoise the recursion
    vector<vector<int>> dp(n+1,vector<int> (w+1,-1));
    return func(w,wt,val,n,dp);
    //-----------------------------------
    
    }
     int func(int w, int wt[],int val[],int n,vector <vector<int>> &dp)
     {
         if(n<=0 || w<=0)
         return 0;
         
         if(dp[n][w]!=-1)
         return dp[n][w];
         
         if(wt[n-1]<=w)
         {
             return dp[n][w]=max(val[n-1]+func(w-wt[n-1],wt,val,n-1,dp),func(w,wt,val,n-1,dp));
         }
         else if(wt[n-1]>w)
         return dp[n][w]=func(w,wt,val,n-1,dp);
         
     }
    
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends