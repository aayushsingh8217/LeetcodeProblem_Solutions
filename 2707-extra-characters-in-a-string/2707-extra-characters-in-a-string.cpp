class Solution {
public:
    unordered_set <string> mp;
    int dp[51];
    int minExtraChar(string s, vector<string>& dictionary) {
       //0/1----> yes/no
        //TC(O(n^2))
        memset(dp,-1,sizeof(dp));
        for(auto &it:dictionary)
        {
            mp.insert(it);
        }
        int len=s.length();
        return solveDp(0,s,len);
        
    }
    int solveDp(int idx,string s,int len)
    {
        //base case
        if(idx>=len)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        string currstring="";
        int extra=len;
        for(int i=idx;i<len;i++)
        {
            currstring.push_back(s[i]);
            int  currExtra;
            if(mp.find(currstring)==mp.end())
                currExtra=currstring.length();
            else
                 currExtra=0;
            int nextExtra=solveDp(i+1,s,len);
            int totalExtra=currExtra+nextExtra;
            extra = min(extra, totalExtra);
        }
        return dp[idx]=extra;
    }
};