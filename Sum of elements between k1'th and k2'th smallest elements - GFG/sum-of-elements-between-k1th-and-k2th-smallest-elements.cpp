//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long> maxh1;
         priority_queue<long long> maxh2;
         for(long long i=0;i<N;i++)
         {
             maxh1.push(A[i]);
             if(maxh1.size()>K1)
             maxh1.pop();
         }
         for(long long i=0;i<N;i++)
         {
             maxh2.push(A[i]);
             if(maxh2.size()>K2)
             maxh2.pop();
         }
         long long k1=maxh1.top();
         long long k2=maxh2.top();
         long long res=0;
         for(long long i=0;i<N;i++)
         {
             if(A[i]>k1 && A[i]<k2)
             res+=A[i];
         }
         return res;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends