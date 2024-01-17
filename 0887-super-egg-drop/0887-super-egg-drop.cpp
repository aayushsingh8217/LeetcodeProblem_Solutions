class Solution {
public:
    int dp[101][10001];
    int superEggDrop(int e, int f) {
       memset(dp,-1,sizeof(dp));
        int res=solve(e,f);
        return res;
    }
    int solve(int e,int f)
    {
        if(f==1 || f==0)
            return f;
        if(e==1)
            return f;
        if(dp[e][f]!=-1)
            return dp[e][f];
        int mn=INT_MAX;
        // for(int k=1;k<=f;k++)
        // {
        //     int low,high;
        //     if(dp[e-1][k-1]!=-1)
        //         low=dp[e-1][k-1];
        //     else
        //     {
        //         low=solve(e-1,k-1);
        //         dp[e-1][k-1]=low;
        //     }
        //     if(dp[e][f-k]!=-1)
        //         high=dp[e][f-k];
        //     else
        //     {
        //         high=solve(e,f-k);
        //         dp[e][f-k]=high;
        //     }
        //     int temp=1+max(high,low);
        //     mn=min(mn,temp);
        // }
        // return dp[e][f]=mn;
        
        
        //Floors saare sorted hai toh kuch aur bhi kar sakte hai ?
        //Sorted----> Binary Search
        
        int low=1,high=f;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int down=solve(e-1,mid-1);
            int up=solve(e,f-mid);
            int temp=1+max(down,up);
            mn=min(mn,temp);
            if(down>up)
                high=mid-1;
            else
                low=mid+1;
            
        }

        return dp[e][f]=mn;
    }
};