class Solution {
public:
    int minDeletions(string s) {
     unordered_map<char, int> freq;
    unordered_map<int, int> freqCount;

   
    for (char c : s) {
        freq[c]++;
    }

    int deletions = 0;

    
    for ( auto& [c, f] : freq) {
        
        freqCount[f]++;

        
        while (freqCount[f] > 1 && f > 0) {
            f--;
            deletions++;
            freqCount[f]++;
        }
    }

    return deletions;   
    }
};