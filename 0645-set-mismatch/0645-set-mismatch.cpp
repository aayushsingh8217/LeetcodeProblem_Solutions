class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
    map<int, int> numCount;

    int n = nums.size();
    
    for (int num : nums) {
        numCount[num]++;
    }

    int duplicate = 0, missing = 0;
    for (int i = 1; i <= n; ++i) {
        if (numCount.find(i) == numCount.end()) {
            missing = i;
        } else if (numCount[i] == 2) {
            duplicate = i;
        }
    }

    result.push_back(duplicate);
    result.push_back(missing);

    return result;
    }
};