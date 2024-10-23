class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int p=100000;
     int pro=0;
     for(int i=0;i<prices.size();i++)
     {
        if(p>prices[i])
        p=prices[i];

        pro=max(pro,(prices[i]-p));
     }

     return pro; 
    }
};