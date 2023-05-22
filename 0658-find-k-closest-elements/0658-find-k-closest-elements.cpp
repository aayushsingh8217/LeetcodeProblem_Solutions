class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //maxh heap chahyea kyuki choti difference wali value rakhni hai
        priority_queue<pair<int,int>> maxh;
        vector <int> res;
        for(int i=0;i<arr.size();i++)
        {
            maxh.push({abs(arr[i]-x),arr[i]});
            if(maxh.size()>k)
                maxh.pop();
        }
        while(maxh.size()>0)
        {
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};