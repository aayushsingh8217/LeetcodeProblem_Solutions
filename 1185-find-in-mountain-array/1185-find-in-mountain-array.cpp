/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakidx(MountainArray &mountainArr)
    {
        int n= mountainArr.length();
        int left = 0, right = n - 1; 
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    int bs1(MountainArray &mountainArr, int s,int e, int target)
    {
        while(s<=e)
        {
            int m = s +(e-s)/2;
            if(mountainArr.get(m) == target)
            return m;
            else if(target > mountainArr.get(m))
            s = m+1;
            else
            e = m-1;
        }
        return -1;
    }
        int bs2(MountainArray &mountainArr, int s,int e, int target)
    {
        while(s<=e)
        {
            int m = s +(e-s)/2;
            if(mountainArr.get(m) == target)
            return m;
            else if(mountainArr.get(m) > target)
            s = m+1;
            else
            e = m-1;
        }
        return -1;
    } 
 
    int findInMountainArray(int target, MountainArray &mountainArr) {
     int pidx = peakidx(mountainArr);
     if(pidx == -1)
     return -1;
     int idx = -1;
     if(mountainArr.get(pidx) == target)
     return pidx;
     idx = bs1(mountainArr,0,pidx-1,target);    
     if(idx != -1)
        return idx;
        else
        idx = bs2(mountainArr,pidx+1,mountainArr.length()-1,target);
        return idx;
    }
};