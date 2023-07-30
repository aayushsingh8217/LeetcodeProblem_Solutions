class Solution {
public:
    int strangePrinter(string s) {
          
    int n = s.length();
        vector<vector<int>> lookup(n, vector<int>(n, -1));
        return dp(s, 0, n - 1, lookup);
    }
      int dp(const string& s, int i, int j, vector<vector<int>>& lookup) {
        if (i > j) {
            return 0;
        }
        if (lookup[i][j] != -1) {
            return lookup[i][j];
        }
        
        lookup[i][j] = dp(s, i, j - 1, lookup) + 1;
        for (int k = i; k < j; ++k) {
            if (s[k] == s[j]) {
                lookup[i][j] = min(lookup[i][j], dp(s, i, k, lookup) + dp(s, k + 1, j - 1, lookup));
            }
        }
        
        return lookup[i][j];
      }
};