class Solution {
public:
    bool check(string& s, int i,int j)
    {
        if(i>j)
        return true;
        if(s[i] == s[j])
        return check(s,i+1,j-1);
        return false;
    }
    int countSubstrings(string s) {
       int n= s.size();
        int res =0;
       for(int i =0;i<n;i++)
       {
        for(int j =i;j<n;j++)
        {
            if(check(s,i,j))
            res++;
        }
       } 
       return res;
    }
};