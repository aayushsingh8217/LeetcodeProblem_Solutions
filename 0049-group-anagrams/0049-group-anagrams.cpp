class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(const auto&str:strs)
        {
            string s=str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);
        }
        for(const auto& it:mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};