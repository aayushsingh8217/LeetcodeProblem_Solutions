class Solution {
public:
 // Amazon,facebook,LinkedIn,Google,Microsoft,Apple,Adobe,Bloomberg,Goldman Sachs
    vector<vector<int>> permute(vector<int>& nums) {
            vector <vector<int>> ans;
        permut(0,nums,ans);
        return ans;
    }
    void permut(int index,vector<int>&nums ,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return ;
            
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            permut(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
};