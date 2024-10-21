class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n=nums.size();
        // int sum=0;
        // for(int i=0;i<=n;i++)
        // {
        //     sum+=i;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     sum-=nums[i];
        // }
        // return sum;

        int x1=0,x2=0;

        for(int i=0;i<=n;i++)
        {
            x1=x1^i;
        }

        for(int j=0;j<n;j++)
        {
            x2=x2^nums[j];
        }

        return x1^x2;

        
    }
};