class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> nums;
        int l=temperatures.size();
        vector <int> final(l);
        for(int i=l-1;i>=0;i--)
        {
            while(!nums.empty() && temperatures[i]>=temperatures[nums.top()])
            {
                nums.pop();
            }
            if(nums.empty())
            {
                final[i]=0;
            }
            else
            {
                final[i]=nums.top()-i;
            }
            nums.push(i);
        }
        return final;
        
    }
};