class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      if (matrix.size() > matrix[0].size()) {
            transpose(matrix);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size() - 1; ++j) {
                matrix[i][j + 1] += matrix[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> prefix_sum(matrix[i].size(), 0);
            for (int j = i; j < matrix.size(); ++j) {
                unordered_map<int, int> lookup;
                lookup[0] = 1;
                for (int k = 0; k < matrix[j].size(); ++k) {
                    prefix_sum[k] += matrix[j][k];
                    if (lookup.find(prefix_sum[k] - target) != lookup.end()) {
                        result += lookup[prefix_sum[k] - target];
                    }
                    ++lookup[prefix_sum[k]];
                }
            }
        }
        return result;   
    }
    private:
    void transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        matrix = result;
    }
};