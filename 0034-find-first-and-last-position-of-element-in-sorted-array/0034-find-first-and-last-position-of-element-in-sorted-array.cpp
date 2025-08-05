class Solution {
public:
int bsfo(vector<int> & nums,int target)
{
    int l =0, h = nums.size()-1;
    int f=-1;
    while(l<=h)
    {
        int m = l+(h-l)/2;
        if(nums[m] == target )
        {
            f = m;
            h = m-1;
        }
        else if(nums[m]> target)
        {
            h = m-1;
        }
        else
        l = m+1;
    }
    return f;
}
int bslo(vector<int> & nums, int target)
{
    int l =0, h = nums.size()-1;
    int lo=-1;
    while(l<=h)
    {
        int m = l+(h-l)/2;
        if(nums[m]== target)
        {
            lo = m;
            l = m+1;
        }
        else if(nums[m]> target)
        {
            h = m-1;
        }
        else
        l = m+1;
    }
    return lo;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        int fo = bsfo(nums,target);
        int lo = bslo(nums,target);
        if(fo!=-1)
        range.push_back(fo);
        else 
        range.push_back(-1);
        if(lo!=-1)
        range.push_back(lo);
        else
        range.push_back(-1);
        return range;
    }
};