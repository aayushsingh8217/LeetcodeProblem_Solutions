class Solution {
public:
    int kthGrammar(int n, int k) {
         if (n == 1) 
             return 0;
    int length = 1 << (n - 1);
    if (k <= length / 2) 
        return kthGrammar(n - 1, k);
    return 1 - kthGrammar(n - 1, k - length / 2);
    }
};