class Solution {
public:
//     vector<int> twoSum(vector<int>& nums, int target) {
       
//       vector <int> res=  solve(nums,target);
// return res;
//     }
//     vector<int> solve(vector <int> &nums,int target)
//     {
//         int sum=0;
//         vector <int> res;
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//             sum=nums[j]+nums[i];
//             if(sum==target)
//             {
//                res.push_back(i);
//                res.push_back(j); 
// break;
//             }
//             }
//         }
// return res;

//     }
 vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>> idx;
       for(int i=0;i<nums.size();i++)
       {
        idx.push_back({nums[i],i});
       }
       sort(idx.begin(),idx.end());
       vector<int> res;
       int low=0,high=idx.size()-1;
       while(low<high)
       {
        if(idx[low].first+idx[high].first==target)
        {
            res.push_back(idx[low].second);
            res.push_back(idx[high].second);
            return res;
        }
        else if(idx[low].first+idx[high].first>target)
        high--;
        else
        low++;
       }
return res;
    }
};