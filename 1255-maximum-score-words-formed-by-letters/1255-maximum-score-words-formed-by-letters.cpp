class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
         unordered_map<char, int> letterCount;
        for (char letter : letters) {
            letterCount[letter]++;
        }

        vector<unordered_map<char, int>> wordCounts(words.size());
        vector<int> wordScores(words.size());

        for (int i = 0; i < words.size(); i++) {
            int wordScore = 0;
            for (char c : words[i]) {
                wordCounts[i][c]++;
                wordScore += score[c - 'a'];
            }
            wordScores[i] = wordScore;
        }

        int result = 0;
        backtracking(words, wordScores, wordCounts,0,  0, letterCount, result);
        return result; 
    }
     void backtracking(const vector<string>& words, const vector<int>& wordScores, const vector<unordered_map<char, int>>& wordCounts,
                      int curr, int currScore, unordered_map<char, int>& letterCount, int& result) {
        result = max(result, currScore);
        for (int i = curr; i < words.size(); i++) {
            bool canForm = true;
            for (const auto& p : wordCounts[i]) {
                if (letterCount[p.first] < p.second) {
                    canForm = false;
                    break;
                }
            }
            if (!canForm) continue;

            for (const auto& p : wordCounts[i]) {
                letterCount[p.first] -= p.second;
            }

            backtracking(words, wordScores, wordCounts, i + 1, currScore + wordScores[i], letterCount, result);

            for (const auto& p : wordCounts[i]) {
                letterCount[p.first] += p.second;
            }
        }
    }
};