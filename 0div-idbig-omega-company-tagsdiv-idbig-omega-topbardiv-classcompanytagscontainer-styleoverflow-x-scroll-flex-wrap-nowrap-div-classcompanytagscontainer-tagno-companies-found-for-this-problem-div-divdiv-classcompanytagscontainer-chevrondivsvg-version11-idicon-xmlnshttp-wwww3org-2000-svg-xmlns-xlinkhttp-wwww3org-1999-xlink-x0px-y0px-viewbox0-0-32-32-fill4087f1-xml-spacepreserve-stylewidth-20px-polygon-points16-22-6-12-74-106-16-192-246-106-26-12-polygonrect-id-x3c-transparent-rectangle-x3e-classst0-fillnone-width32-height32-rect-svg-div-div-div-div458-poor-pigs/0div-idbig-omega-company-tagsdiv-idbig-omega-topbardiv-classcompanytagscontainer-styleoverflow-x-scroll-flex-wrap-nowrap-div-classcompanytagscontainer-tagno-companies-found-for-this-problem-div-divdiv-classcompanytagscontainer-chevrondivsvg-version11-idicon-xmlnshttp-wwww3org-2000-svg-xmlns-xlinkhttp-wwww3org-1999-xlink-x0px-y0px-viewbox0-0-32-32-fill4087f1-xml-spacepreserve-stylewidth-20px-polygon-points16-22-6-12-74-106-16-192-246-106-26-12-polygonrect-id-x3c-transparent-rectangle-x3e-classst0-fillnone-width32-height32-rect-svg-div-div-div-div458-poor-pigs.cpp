class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
         int pigs = 0;
        int tests = (minutesToTest / minutesToDie) + 1;
        
        while (pow(tests, pigs) < buckets) {
            pigs++;
        }
        
        return pigs;
    }
};