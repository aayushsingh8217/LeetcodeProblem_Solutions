class Solution {
public:
    string customSortString(string order, string s) {
       unordered_map<char, int> charToIndex;
    for (int i = 0; i < order.length(); ++i) {
        charToIndex[order[i]] = i;
    }
    sort(s.begin(), s.end(), [&](char a, char b) {
        return charToIndex[a] < charToIndex[b];
    });

    return s; 
    }
};