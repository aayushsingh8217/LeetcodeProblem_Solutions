class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
     unordered_map<int,int> mp;
        int flag=0;
        for(auto it:nums)
        {
            if(mp.find(it)!=mp.end())
            {
                flag+=mp[it];
                mp[it]++;
            }
            else
            {
                mp[it]=1;
            }
        }
        return flag;
    }
};