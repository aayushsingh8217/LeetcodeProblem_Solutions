class Solution {
public:
    
    int countHomogenous(string s) {
        int mod=1e9+7;
        int len=s.length();
        long long res=0;
        int flag=0;
        for(int i=0;i<len;i++)
        {
            if( i>0 && s[i]==s[i-1] )
            {
                flag+=1;
            }
            else
            {
                flag=1;
            }
            res=(res+flag)%mod;
            }
        return res;
    }
};