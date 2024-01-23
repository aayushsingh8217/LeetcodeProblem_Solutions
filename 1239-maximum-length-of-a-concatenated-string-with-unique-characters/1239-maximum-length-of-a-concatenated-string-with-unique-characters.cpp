class Solution {
public:
    int maxLength(vector<string>& arr) {
     vector<int> convert;
        int res=0;
        int temp=0;
        for(string& it:arr)
        {
            unordered_set<char> s(begin(it),end(it));
            
            if(s.size()!=it.length())
                continue;
            
                int val=0;
                for(char & c:it)
                {
                    val=((val)|(1<<(c-'a')));
                }
                convert.push_back(val);
            
            
                
        }
        solve(0,temp,res,convert);
        return res;
        
    }
    void solve(int idx,int temp,int& res,vector<int>& convert)
    {
        res=max(res,__builtin_popcount(temp));
        for(int i=idx;i<convert.size();i++)
        {
            if((temp & convert[i])==0)
                solve(i+1,temp | convert[i],res,convert);
        }
    }
};