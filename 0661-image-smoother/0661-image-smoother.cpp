class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                int count = 0;

                for (int ni = i - 1; ni <= i + 1; ++ni) {
                    for (int nj = j - 1; nj <= j + 1; ++nj) {
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            sum += img[ni][nj];
                            count++;
                        }
                    }
                }

                result[i][j] = sum / count;
            }
        }

        return result; 
    }
};