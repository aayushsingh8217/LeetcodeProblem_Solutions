class Solution {
public:
    string minWindow(string s, string t) {
unordered_map<char, int> mp;
        string res = "";
        int size = INT_MAX;
        int i = 0, j = 0;
        int st, ed;
        for (auto it : t) {
            mp[it]++;
        }
        int count = mp.size();
        while (j < s.size() && i < s.size()) {
            if (mp.count(s[j]) > 0) {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
            }
            j++;
            while (count == 0) {
                if (j - i < size) {
                    size = j - i;
                    st = i;
                    ed = j;
                }
                if (mp.count(s[i]) > 0) {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        count++;
                }
                i++;
            }
        }
        for (int k = st; k < ed; k++)
            res += s[k];
        return res;
    }
};