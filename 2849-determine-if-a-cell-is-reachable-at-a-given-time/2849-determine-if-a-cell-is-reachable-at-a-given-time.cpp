class Solution {
public:
   
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        int diff1 = abs(fx - sx), diff2= abs(fy - sy);
        return max(diff1, diff2) <= t;

    }
};