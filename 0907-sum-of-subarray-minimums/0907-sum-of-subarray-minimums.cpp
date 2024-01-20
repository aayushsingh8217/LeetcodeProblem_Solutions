class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
      const int M = 1000000007;

        int n = A.size();
        vector<int> left(n, 0), right(n, 0);

        stack<pair<int, int>> s1, s2;

        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first > A[i]) {
                count += s1.top().second;
                s1.pop();
            }
            left[i] = count;
            s1.push({A[i], count});
        }

        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!s2.empty() && s2.top().first >= A[i]) {
                count += s2.top().second;
                s2.pop();
            }
            right[i] = count;
            s2.push({A[i], count});
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + (long long)A[i] * left[i] * right[i]) % M;
        }

        return res;  
    }
};