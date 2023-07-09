class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        vector <int> res;
        int fo=-1,lo=-1;
        if(nums.size()==1 && nums[0]==target)
        {
            res.push_back(0);
            res.push_back(0);
            return res;
        }
        else if(nums.size()==1 && nums[0]!=target)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        else
        {
            //First occurence
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]==target)
                {
                    fo=mid;
                    end=mid-1;
                }
                else if(target>nums[mid])
                    start=mid+1;
                else
                    end= mid-1;
            }
            res.push_back(fo);
            //Last occurence
            start=0;
            end=nums.size()-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]==target)
                {
                    lo=mid;
                    start=mid+1;
                }
                else if(target>nums[mid])
                    start=mid+1;
                else
                    end=mid-1;
            }
            res.push_back(lo);
            
        }
        return res;
    }
};