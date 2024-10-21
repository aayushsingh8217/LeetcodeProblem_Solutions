class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<2)
        return;
       reverse(nums.begin(),nums.end());
       reverse(nums.begin()+k,nums.end()); 
       reverse(nums.begin(),nums.begin()+k);
    }
};