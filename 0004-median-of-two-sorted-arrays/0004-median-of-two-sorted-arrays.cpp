class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m;
        double res=0;
        for(int i=0;i<nums1.size();i++)
        {
            m.push_back(nums1[i]);
        }
         for(int i=0;i<nums2.size();i++)
        {
            m.push_back(nums2[i]);
        }
        sort(m.begin(),m.end());
        if(m.size()%2!=0)
        return (double)(m[m.size()/2]);
        else 
        {
            res = (double)(m[m.size()/2]+m[m.size()/2-1])/2;
        }
        return res;

    }
};