class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) {
            return 1.0;
        }
        
        unordered_map<int, double> lookup;
        n = (n + 24) / 25;
        return dp(n, n, lookup);  
    }
     double dp(int a, int b, unordered_map<int, double>& lookup) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1.0;
        }
        if (b <= 0) {
            return 0.0;
        }
        
        int key = a * 1000 + b; 
        if (lookup.find(key) != lookup.end()) {
            return lookup[key];
        }
        
        double probability = 0.25 * (dp(a - 4, b, lookup) +
                                    dp(a - 3, b - 1, lookup) +
                                    dp(a - 2, b - 2, lookup) +
                                    dp(a - 1, b - 3, lookup));
        lookup[key] = probability;
        return probability;
    }
};