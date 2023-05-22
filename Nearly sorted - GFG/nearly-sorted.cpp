//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector <int> res;
        //mujhse sorted chadiyea ascending order toh min heap
        priority_queue<int,vector<int>,greater<int>> minh;
        for(int i=0;i<num;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>K)
            {
                res.push_back(minh.top());
                minh.pop();
            }
        }
        while(minh.size()>0)
        {
            res.push_back(minh.top());
            minh.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends