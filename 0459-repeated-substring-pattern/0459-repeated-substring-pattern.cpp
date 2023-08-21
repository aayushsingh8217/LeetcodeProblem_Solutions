class Solution {
public:
    bool repeatedSubstringPattern(string s) {
          int n = s.length();
    
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) {
            std::string substring = s.substr(0, len);
            std::string constructed;
            
            for (int i = 0; i < n / len; ++i) {
                constructed += substring;
            }
            
            if (constructed == s) {
                return true;
            }
        }
    }
    
    return false;
    }
};