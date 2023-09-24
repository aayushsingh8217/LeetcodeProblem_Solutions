class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(101, vector<double>(101, 0.0));
    glasses[0][0] = poured;

    for (int row = 0; row <= query_row; ++row) {
        for (int glass = 0; glass <= row; ++glass) {
            double overflow = (glasses[row][glass] - 1.0) / 2.0;
            if (overflow > 0) {
                glasses[row + 1][glass] += overflow;
                glasses[row + 1][glass + 1] += overflow;
            }
        }
    }

    return min(1.0, glasses[query_row][query_glass]);

    }
};