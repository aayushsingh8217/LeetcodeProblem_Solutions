class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t)
        // return true;
        // else
        // return false;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            char key=s[i];
            mp[key]++;
        }
        for(int i=0;i<t.size();i++)
        {
            char key=t[i];
            mp[key]--;
        }
        for(const auto &it:mp)
        {
            if(it.second!=0)
            return false;
        }
        return true;
    }
};