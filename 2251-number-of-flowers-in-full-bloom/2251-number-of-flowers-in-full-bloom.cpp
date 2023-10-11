class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
vector<int> start, end;
        
        for (const auto& flower : flowers) {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> result;
        for (int p : people) {
            int startCount = upper_bound(start.begin(), start.end(), p) - start.begin();
            int endCount = lower_bound(end.begin(), end.end(), p) - end.begin();
            result.push_back(startCount - endCount);
        }
        
        return result;
    }
};