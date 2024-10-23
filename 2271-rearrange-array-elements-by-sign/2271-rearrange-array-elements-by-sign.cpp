class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        if(nums.size()<=2)
        {
         if(nums[0]<0){
          res[0]=nums[1];
          res[1]=nums[0];
         }
         else
         {
            res[0]=nums[0];
            res[1]=nums[1];
         }
          return res;
        }

        int pi=0,ni=1;
       
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                res[pi]=nums[i];
                pi+=2;
            }
            else 
            {
                res[ni]=nums[i];
                ni+=2;
            }
        }

        return res;

    }
};