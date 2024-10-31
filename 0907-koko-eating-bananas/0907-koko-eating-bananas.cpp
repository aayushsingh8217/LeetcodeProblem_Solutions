class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=*max_element(begin(piles),end(piles));
        while(l<r)
        {
            int m=l+(r-l)/2;
             if(caneat(piles,m,h))
             {
                r=m;
             }
             else 
             l=m+1;
        }

        return l;
    }
    bool caneat(vector<int> & piles,int mid,int h)
    {
        int ah=0;

        for(auto& it: piles)
        {
            ah+=it/mid;

            if(it%mid!=0)
            ah+=1;
        }
        if(ah<=h)
        return true;
        else
        return false;
    }
};