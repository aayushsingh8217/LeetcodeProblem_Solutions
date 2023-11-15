class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int maxVal=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>maxVal)
                maxVal+=1;
        }
        return maxVal;
    }
};