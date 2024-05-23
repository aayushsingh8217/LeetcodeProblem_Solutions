class Solution {
public:
    int countBeautifulSubsets;
    int difference;

    void findBeautifulSubsets(vector<int>& nums, int index, unordered_map<int, int>& elementCount) {
        if (index == nums.size()) {
            countBeautifulSubsets++;
            return;
        }

        findBeautifulSubsets(nums, index+1 , elementCount);

        if (!elementCount[nums[index] - difference] && !elementCount[nums[index] + difference]) {
            elementCount[nums[index]]++;
            findBeautifulSubsets(nums, index + 1, elementCount);
            elementCount[nums[index]]--;  // Backtrack
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        countBeautifulSubsets = 0;
        difference = k;
        unordered_map<int, int> elementCount;

        findBeautifulSubsets(nums, 0, elementCount);

        return countBeautifulSubsets - 1; 
    }
};