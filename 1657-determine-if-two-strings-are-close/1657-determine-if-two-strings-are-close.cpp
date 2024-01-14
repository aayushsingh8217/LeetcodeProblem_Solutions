class Solution {
public:
    bool closeStrings(string word1, string word2) {
      if (word1.length() != word2.length()) {
            return false;
        }

        unordered_map<char, int> cnt1, cnt2;

        for (char ch : word1) {
            cnt1[ch]++;
        }

        for (char ch : word2) {
            cnt2[ch]++;
        }

        set<char> keys1, keys2;
        for (const auto& entry : cnt1) {
            keys1.insert(entry.first);
        }

        for (const auto& entry : cnt2) {
            keys2.insert(entry.first);
        }

        if (keys1 != keys2) {
            return false;
        }

        unordered_map<int, int> freq1, freq2;

        for (const auto& entry : cnt1) {
            freq1[entry.second]++;
        }

        for (const auto& entry : cnt2) {
            freq2[entry.second]++;
        }

        return freq1 == freq2;  
    }
};