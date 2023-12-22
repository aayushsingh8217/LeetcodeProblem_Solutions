class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
    int totalOnes = 0;
    for (char ch : s) {
        if (ch == '1') {
            totalOnes++;
        }
    }
    int maxScore = 0;
    int zerosLeft = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '0') {
            zerosLeft++;
        } else {
            totalOnes--;
        }
        int score = zerosLeft + totalOnes;
        maxScore = max(maxScore, score);
    }
    return maxScore;
    }
};