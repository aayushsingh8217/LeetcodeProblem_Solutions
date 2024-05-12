class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
       int n = grid.size();
    vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            int maxVal = grid[i - 1][j - 1];
            for (int k = i - 1; k <= i + 1; ++k) {
                for (int l = j - 1; l <= j + 1; ++l) {
                    maxVal = max(maxVal, grid[k][l]);
                }
            }
            maxLocal[i - 1][j - 1] = maxVal;
        }
    }

    return maxLocal;   
    }
};