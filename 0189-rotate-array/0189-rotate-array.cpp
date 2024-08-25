class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       //-------------Counter clockwise rotation-----------------
       
        // k=k%nums.size();

        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin()+k,nums.end());

        // reverse(nums.begin(),nums.end());


        //---------------clockwise rotation--------------------

        int n = nums.size();
k = k % n;  
int idxfromstart = n - k;
reverse(nums.begin(), nums.begin() + idxfromstart);
reverse(nums.begin() + idxfromstart, nums.end());
reverse(nums.begin(), nums.end());
    }
};