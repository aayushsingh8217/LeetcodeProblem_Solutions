class Solution {
public:
    int countPalindromicSubsequence(string s) {
     vector<int> first(26, s.length());
        vector<int> last(26, -1);

        for (int i = 0; i < s.length(); ++i) {
            int index = s[i] - 'a';
            first[index] = min(first[index], i);
            last[index] = max(last[index], i);
        }

        int result = 0;
        for (int c = 0; c < 26; ++c) {
            unordered_set<char> uniqueChars;
            for (int i = first[c] + 1; i < last[c]; ++i) {
                uniqueChars.insert(s[i]);
            }
            result += uniqueChars.size();
        }

        return result;
    }
};