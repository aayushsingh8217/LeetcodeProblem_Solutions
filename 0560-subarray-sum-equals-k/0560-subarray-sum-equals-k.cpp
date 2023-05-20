class Solution {
public:
    //facebook,amazon
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       vector <int> prefixsum(nums.size());
       int res=0;
       prefixsum[0]=nums[0];
       for(int i=1;i<nums.size();i++)
       {
           prefixsum[i]=prefixsum[i-1]+nums[i];
       }
       for(int i=0;i<nums.size();i++)
       {
           if(prefixsum[i]==k)
           res++;
           if(mp.find(prefixsum[i]-k)!=mp.end())
           res=res+mp[prefixsum[i]-k];
           mp[prefixsum[i]]++;
       }
    return res;
    }
};