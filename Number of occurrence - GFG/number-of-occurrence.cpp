//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    // code herclass Solution {
        int start=0,end=n-1;
        // vector <int> res(2,-1); isse kya hoga jab first and last occurnce found hogi toh vo thirst and fourth position par push ho jaeg
        int fo=-1,lo=-1;
       int res=0;
            //First occurence
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]==target)
                {
                    fo=mid;
                    end=mid-1;
                }
                else if(target>nums[mid])
                    start=mid+1;
                else
                    end= mid-1;
            }
            //Last occurence
            start=0;
            end=n-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]==target)
                {
                    lo=mid;
                    start=mid+1;
                }
                else if(target>nums[mid])
                    start=mid+1;
                else
                    end=mid-1;
            }
            
            if(lo==-1 && fo==-1)
        return res;
        else
        return (lo-fo+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends