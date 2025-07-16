class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set <int> sr;
        set <int> sc;
        for(int i =0;i<m;i++)
        {
            for(int j =0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    sr.insert(i);
                    sc.insert(j);
                }
            }
        }
        for(auto it = sr.begin() ;it != sr.end(); it++)
        {
            for(int col = 0; col<n; col++ )
            {
                matrix[*it][col] = 0;
            }
        }
        for(auto it = sc.begin() ;it != sc.end(); it++)
        {
            for(int row = 0; row < m; row++ )
            {
                matrix[row][*it] = 0;
            }
        }
    }
};