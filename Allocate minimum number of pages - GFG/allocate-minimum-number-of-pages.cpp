//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)
        return -1;
        if(N==1 && M==1)
        return A[0];
        int start=*max_element(A,A+N);
         int end = 0;
         for(int i=0;i<N;i++)
        {
            end+=A[i];
        }
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isValid(A,N,M,mid)==true)
            {
                res=mid;
                end=mid-1;
            }
            else 
            {
                start=mid+1;
            }
        }
        return res;
    }
    bool isValid(int  A[],int N,int M,int mx)
    {
        int student=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum>mx)
            {
                student++;
                sum=A[i];
            }
            
        }
        if(student>M)
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends