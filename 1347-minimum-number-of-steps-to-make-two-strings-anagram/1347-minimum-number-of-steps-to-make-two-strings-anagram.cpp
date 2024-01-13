class Solution {
public:
    int minSteps(string s, string t) {
        if(s.size()!=t.size())
            return -1;
        int res=0;
        unordered_map<char,int> freqS,freqT;
        for(auto it:s)
        {
            freqS[it]++;
        }
        for(auto it:t)
        {
            freqT[it]++;
        }
        for(auto &it:freqS)
        {
            char c=it.first;
            int countDiff=freqS[c]-freqT[c];
            res += (countDiff > 0) ? countDiff : 0;
        }
        return res;
    }
};