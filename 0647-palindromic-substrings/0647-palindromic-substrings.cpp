class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
    int count = 0;
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    
    for (int i = 0; i < n; ++i) {
        isPalindrome[i][i] = true;
        count++;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true;
            count++;
        }
    }
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                isPalindrome[i][j] = true;
                count++;
            }
        }
    }
    
    return count;
    }
};