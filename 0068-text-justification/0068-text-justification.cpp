class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int begin = 0, length = 0;
        
        for (int i = 0; i < words.size(); ++i) {
            if (length + words[i].length() + (i - begin) > maxWidth) {
                result.push_back(connect(words, maxWidth, begin, i, length, false));
                begin = i;
                length = 0;
            }
            length += words[i].length();
        }

        // Last line.
        result.push_back(connect(words, maxWidth, begin, words.size(), length, true));
        
        return result;
    }
    private:
    int addSpaces(int i, int spaceCnt, int maxWidth, bool is_last) {
        if (i < spaceCnt) {

            return is_last ? 1 : (maxWidth / spaceCnt) + int(i < maxWidth % spaceCnt);
        }
        return 0;
    }

    string connect(vector<string>& words, int maxWidth, int begin, int end, int length, bool is_last) {
        string line;
        int n = end - begin;
        for (int i = 0; i < n; ++i) {
            line += words[begin + i];
            line += string(addSpaces(i, n - 1, maxWidth - length, is_last), ' ');
        }
        
        if (line.length() < maxWidth) {
            line += string(maxWidth - line.length(), ' ');
        }
        
        return line;
    }
};