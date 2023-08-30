class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        //Non decreasing ---> equal or increasing
        // Parts-1=operation
        //Greedy---> bade number ko todna hai
        //Traversing from right to left
        int len=nums.size();
        long long numOfOperation=0;
        for(int i=len-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
            {
            continue;
            }
            int minParts=nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0)
            minParts+=1;
            numOfOperation+=minParts-1;
            nums[i]=nums[i]/minParts;
        }
        return numOfOperation;
    }
};