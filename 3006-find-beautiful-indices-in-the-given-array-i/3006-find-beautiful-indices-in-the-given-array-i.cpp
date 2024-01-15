class Solution {
public://KMP
    void computeLPS(vector<int>& LPS,string& pat,int n)
    {
        int len=0;
        LPS[0]=0;
        int i=1;
        while(i<n)
        {
            if(pat[i]==pat[len])
            {
                len++;
                LPS[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=LPS[len-1];
                    
                }
                else
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n=s.size();
        int p=a.size();
        int q=b.size();
        vector<int> LPSa(p,0);
        vector<int> LPSb(q,0);
        computeLPS(LPSa,a,p);
        computeLPS(LPSb,b,q);
        vector<int> res_a;
        vector<int> res_b;
         int i=0,j=0;
        while(i<n)
        {
            if(s[i]==a[j])
            {
                i++;
                j++;
            }
            if(j==p)
            {
                res_a.push_back(i-p);
                j=LPSa[j-1];
            }
            else if(s[i]!=a[j])
            {
                if(j!=0)
                    j=LPSa[j-1];
                else
                    i++;
            }
        }
        i=0,j=0;
        while(i<n)
        {
            if(s[i]==b[j])
            {
                i++;
                j++;
            }
            if(j==q)
            {
                res_b.push_back(i-q);
                j=LPSb[j-1];
            }
            else if(s[i]!=b[j])
            {
                if(j!=0)
                    j=LPSb[j-1];
                else
                    i++;
            }
        }
        vector<int> res;
        for(int &i : res_a) {
           
            
            int left_limit  = max(0, i - k);
            int right_limit = min(n-1, i + k);
            
            auto it = lower_bound(begin(res_b), end(res_b), left_limit);
            
            if(it != res_b.end() && *it <= right_limit) {
                res.push_back(i);
            }
        }
        return res;
        
    }
};