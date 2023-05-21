
class Solution {
public:
    vector<int> del_i = {1, 0, -1, 0};
    vector<int> del_j = {0, 1, 0, -1};

    bool outofboundscheck(int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col) return false;
        return true;
    }

    void IslandCheckMark(vector<vector<int>>& A, int i, int j) {
        A[i][j] = -1;

        for (int k = 0; k < 4; ++k)
        {
            int next_i = i + del_i[k];
            int next_j = j + del_j[k];

            if (outofboundscheck(next_i, next_j, A.size(), A[0].size()) && A[next_i][next_j] == 1)
                IslandCheckMark(A, next_i, next_j);
        }

    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();


        int flag = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j <n; ++j)
            {
                if (grid[i][j] == 1) {
                    flag = 1;
                    IslandCheckMark(grid, i, j);
                    break;
                }
            }

            if (flag) break;
        }

        // queue that represent flips on a particular path
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j <n; ++j)
            {
                if (grid[i][j] == -1) {
                    q.push({i * m + j, 0});
                }
            }
        }

        while (!q.empty()) {
            int idx = q.front().first;
            int i = idx / m;
            int j = idx % m;

            int flips = q.front().second;

            q.pop();

            for (int k = 0; k < 4; ++k)
            {
                int next_i = i + del_i[k];
                int next_j = j + del_j[k];
                int next_index = next_i *m + next_j;

                if (outofboundscheck(next_i, next_j, m, n)) {
                    if (grid[next_i][next_j] == 1) 
                        return flips;

                    if (grid[next_i][next_j] == -1) 
                        continue;

                    q.push({next_index, flips + 1});

                    grid[next_i][next_j] = -1;
                }
            }


        }
        return -1;

    }
};