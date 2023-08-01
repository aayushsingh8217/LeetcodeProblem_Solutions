class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
          vector<vector<int>> result;
    vector<int> current_combination;
    backtrack(n, k, 1, current_combination, result);
    return result;
    }
    void backtrack(int n, int k, int start, vector<int>& current_combination, vector<vector<int>>& result) {
    if (current_combination.size() == k) {
        result.push_back(current_combination);
        return;
    }

    for (int i = start; i <= n; ++i) {
        current_combination.push_back(i);
        backtrack(n, k, i+1 , current_combination, result);
        current_combination.pop_back();
    }
}
};