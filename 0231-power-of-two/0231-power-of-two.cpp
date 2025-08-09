class Solution {
public:
    // bool isValid(int n)
    // {
    //     n = abs(n);
    //     int res = 2;
    //     if(n==1)
    //     return true;
    //     while(res<=n)
    //     {
    //         if(n == res)
    //         return true;
    //         else
    //         res = res*2;
    //     }
    //     return false;
    // }  // will give overflow error now 
    bool isPowerOfTwo(int n) {
        //return isValid(n);
        if (n > 0)
        {
            return ((n &(n-1))==0);
        }
        return false;
    }
};