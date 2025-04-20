class Solution {
public:
    int numRabbits(vector<int>& answers) {
         unordered_map<int, int> ct;
    int res= 0;
    for (int it : answers) {
        ct[it]++;
    }
    for (auto& [x, freq] : ct) {
        int gS = x + 1;
        int gp = (freq + gS - 1) / gS;
        res+=gp * gS;
    }
    return res;
    }
};