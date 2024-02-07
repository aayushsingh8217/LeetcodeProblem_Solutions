class Solution {
public:
 static bool cmp(pair <int, char> a, pair <int, char> b){
      return a.first < b.first;
   }
    string frequencySort(string s) {
        vector <pair<int,char>> num;
        map <char,int> mi;
        for(int i=0;i<s.size();i++)
    {
        mi[s[i]]++;
    }
map<char,int>::iterator it=mi.begin();
while(it!=mi.end())
{
num.push_back({it->second, it->first});
         it++;
      }
      sort(num.rbegin(), num.rend(), cmp);
      string ans = "";
      for(int i = 0; i < num.size(); i++){
         int t = num[i].first;
         while(t--)ans += num[i].second;
      }
      return ans;
    }
};