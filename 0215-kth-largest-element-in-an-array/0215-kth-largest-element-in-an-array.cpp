class Solution {
public:
    //kth largest element 
    //sorting kar skte hai lekin usse phr nlogn ka TC aayega
    //Heap use kr sakte hai saari conditions bhi satisfy kar rahi hai
    //largest toh min heap
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue <int,vector<int>,greater<int>> minh;
        if(nums.size()<0)
            return -1;
        else if(nums.size()==0)
            return nums[0];
        for(int i=0;i<nums.size();i++)
        {
            minh.push(nums[i]);
            if(minh.size()>k)
                minh.pop();
        }
        return minh.top();
    }
};