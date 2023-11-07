class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
         int n = dist.size();
        for (int i = 0; i < n; i++) {
            dist[i] = (dist[i] - 1) / speed[i];
        }
        sort(dist.begin(), dist.end());
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (result > dist[i]) {
                break;
            }
            result += 1;
        }
        return result;
    }
};