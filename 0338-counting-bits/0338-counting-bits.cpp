class Solution {
public:
    vector<int> countBits(int n) {
        //Method-->1 O(nlogn)
        // vector<int>res;
        // for(int i=0;i<=n;i++)
        // {
        //     int ones=__builtin_popcount(i);
        //     res.push_back(ones);
        // }
        // return res;
        
        //using bit manipulation
        //Method--->2 O(N)
        vector <int> res(n+1);
         if(n==0)
            return res;
        res[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2!=0)
            {
                res[i]=res[i/2]+1;
            }
            else
            {
                res[i]=res[i/2];
            }
        }
        return res;
        
    }
};