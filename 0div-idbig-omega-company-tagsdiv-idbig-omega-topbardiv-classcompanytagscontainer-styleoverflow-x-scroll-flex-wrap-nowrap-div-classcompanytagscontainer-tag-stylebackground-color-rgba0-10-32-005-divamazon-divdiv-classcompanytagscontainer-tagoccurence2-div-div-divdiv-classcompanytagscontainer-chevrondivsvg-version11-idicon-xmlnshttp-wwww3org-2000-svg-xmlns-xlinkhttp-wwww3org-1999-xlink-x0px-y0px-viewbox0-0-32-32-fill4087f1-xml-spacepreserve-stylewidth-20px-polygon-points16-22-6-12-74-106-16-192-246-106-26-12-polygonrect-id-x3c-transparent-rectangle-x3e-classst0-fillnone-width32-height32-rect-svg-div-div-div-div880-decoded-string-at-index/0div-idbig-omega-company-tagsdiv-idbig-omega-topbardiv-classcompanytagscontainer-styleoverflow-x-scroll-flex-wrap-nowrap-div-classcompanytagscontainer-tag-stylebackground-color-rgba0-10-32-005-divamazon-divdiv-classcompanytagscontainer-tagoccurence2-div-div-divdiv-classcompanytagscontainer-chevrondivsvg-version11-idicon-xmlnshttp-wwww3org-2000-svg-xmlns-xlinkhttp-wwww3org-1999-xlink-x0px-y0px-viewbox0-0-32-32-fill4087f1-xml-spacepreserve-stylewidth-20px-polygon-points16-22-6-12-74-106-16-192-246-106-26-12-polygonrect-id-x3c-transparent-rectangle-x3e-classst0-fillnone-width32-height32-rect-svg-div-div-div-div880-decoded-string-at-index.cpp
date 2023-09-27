class Solution {
public:
    string decodeAtIndex(string S, int K) {
  long long i = 0;
        
        
        for (char c : S) {
            if (isdigit(c)) {
                i *= (c - '0');
            } else {
                i++;
            }
        }

        
        for (int j = S.length() - 1; j >= 0; j--) {
            K %= i;
            if (K == 0 && isalpha(S[j])) {
                return string(1, S[j]); 
            }

            if (isdigit(S[j])) {
                i /= (S[j] - '0');
            } else {
                i--;
            }
        }

        return "";
    }
};