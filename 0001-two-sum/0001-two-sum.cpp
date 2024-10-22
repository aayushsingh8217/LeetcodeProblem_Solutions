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

       int left=0;
       int right=nums.size()-1;

       while(left<right)
       {
        if(idx[left].first+idx[right].first==target)
        {
            res.push_back(idx[left].second);
            res.push_back(idx[right].second);
            return res;
        }
        else if(idx[left].first+idx[right].first>target)
        right--;
        else 
        left++;

       }

       return res;
    }
};