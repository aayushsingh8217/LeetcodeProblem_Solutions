class Solution {
public:
    unordered_map<string,bool> mp_dp;
    bool isScramble(string s1, string s2) {
        mp_dp.clear();
        mp_dp=unordered_map<string,bool>(false);
        //to check if they have same characters or not
        vector<int> freq(26,0);
        for(int i=0;i<s1.size();i++)
        {
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
                return false;
        }
        bool res=solve(s1,s2);
        return res;
    }
    bool solve(string a,string b)
    {
        string key=a+' '+b;
        if(a==b)
            return true;
        if(a.size()<=1 || b.size()<=1)
            return false;
        if(mp_dp.find(key)!=mp_dp.end())
            return mp_dp[key];
        int n=a.size();
        bool flag=false;
        for(int i=1;i<n;i++)
        {
            bool Swapped=solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i),b.substr(0,n-i));
            bool notSwapped=solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i));
            if(Swapped|notSwapped)
            {
                flag=true;
                break;
            }
        }
        return mp_dp[key]=flag;
    }
};