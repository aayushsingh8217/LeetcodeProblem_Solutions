class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrences;
    for (int num : arr) {
        occurrences[num]++;
    }
    unordered_set<int> uniqueCount;
    for (const auto& kv : occurrences) {
        if (uniqueCount.count(kv.second) > 0) {
            return false;
        }
        uniqueCount.insert(kv.second);
    }
    return true;
    }
};