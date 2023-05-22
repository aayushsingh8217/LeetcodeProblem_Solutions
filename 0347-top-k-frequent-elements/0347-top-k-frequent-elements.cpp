class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          unordered_map<int, int> freq;
         priority_queue<pair<int, int>> pqh;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            ++freq[nums[i]];
        }
        for (auto it = freq.begin(); it != freq.end(); ++it)
        {
            pqh.emplace(-(it->second), it->first);
            if (pqh.size() == k+1 ) 
            {
                pqh.pop();
            }
        }
        while (!pqh.empty()) 
        {
            res.emplace_back(pqh.top().second);
            pqh.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};