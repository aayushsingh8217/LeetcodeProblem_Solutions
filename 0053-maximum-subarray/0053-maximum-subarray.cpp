class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       long long maxs=INT_MIN,sum=0;
       int s=0,si=-1,se=-1;
       for(int i=0;i<nums.size();i++)
       {

        if(sum==0)
        s=i;
         sum+=nums[i];

        if(sum>maxs){
        maxs=sum;
        si=s;
        se=i;
        }

        if(sum<0)
        sum=0;
       
       
       }

       return maxs;
    }
};