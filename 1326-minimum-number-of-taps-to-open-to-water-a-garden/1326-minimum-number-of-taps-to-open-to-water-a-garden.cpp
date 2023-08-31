class Solution {
public:
    map<pair<int,int>,int> dp;
    int minTaps(int n, vector<int>& ranges) {
       vector<pair<int, int>> intervals; 
        for (int i = 0; i <= n; ++i) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            intervals.push_back({start, end});
        }
        
        sort(intervals.begin(), intervals.end());
        
        int minTaps = 0;
        int currentEnd = 0;
        int nextEnd = 0;
        int i = 0;
        
        while (currentEnd < n) {
            while (i < intervals.size() && intervals[i].first <= currentEnd) {
                nextEnd = max(nextEnd, intervals[i].second);
                ++i;
            }
            
            if (currentEnd == nextEnd) {
                return -1; // No tap found to extend coverage
            }
            
            ++minTaps;
            currentEnd = nextEnd;
        }
        
        return minTaps;
        
    }
   
};