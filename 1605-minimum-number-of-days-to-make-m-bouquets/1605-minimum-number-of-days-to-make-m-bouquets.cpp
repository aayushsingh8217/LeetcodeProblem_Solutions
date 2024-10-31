class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(static_cast<long long>(n)<static_cast<long long>(m)*static_cast<long long>(k))
        return -1;

        int l=*min_element(begin(bloomDay),end(bloomDay));
        int r=*max_element(begin(bloomDay),end(bloomDay));

        while(l<r)
        {
            int mid=l+(r-l)/2;

            if(canform(bloomDay,mid,m,k)){
                r=mid;
            }
            else
            l=mid+1;
        }

        return l;
    }
    bool canform(vector<int>& bloomDay,int mid,int m,int k)
    {
 int bouquets = 0;
        int flowers = 0;

        for (const int& day : bloomDay) {
            if (day <= mid) {
                flowers++;  // Count consecutive blooming flowers
                if (flowers == k) {  // Enough for one bouquet
                    bouquets++;
                    flowers = 0;  // Reset for the next bouquet
                    if (bouquets >= m) return true;  // Early exit if we've met the requirement
                }
            } else {
                flowers = 0;  // Reset if flowers are not consecutive
            }
        }
        
        return bouquets >= m;
    }
};