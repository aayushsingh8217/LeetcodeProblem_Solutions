class Solution {
public:
    bool find132pattern(vector<int>& nums) {
     int n = nums.size();
        if (n < 3) {
            return false; 
        }
        
        stack<int> potentialK;
        int potentialJ = INT_MIN; 
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < potentialJ) {
                return true;
            }
            

            while (!potentialK.empty() && nums[i] > potentialK.top()) {
                potentialJ = potentialK.top();
                potentialK.pop();
            }
            
            potentialK.push(nums[i]);
        }
        
        return false; 
        
    }
};