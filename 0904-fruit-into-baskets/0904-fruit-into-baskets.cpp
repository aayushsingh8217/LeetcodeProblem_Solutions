class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int k=2;//length of the window
      unordered_map<int,int> mp;
      int i=0,j=0,mx=1;
      while(j<fruits.size())
      {
          mp[fruits[j]]++;
        //   if(mp.size()<k)
        //   j++;
          if(mp.size()<=k)
          {
              mx=max(mx,j-i+1);
              j++;
          }
          else if(mp.size()>k)
          {
              while(mp.size()>k)
              {
                  mp[fruits[i]]--;
                  if(mp[fruits[i]]==0)
                  mp.erase(fruits[i]);
                  i++;
              }
              if(mp.size()==k)
              mx=max(mx,j-i+1);
              j++;
          }

      }
      return mx;
    }
};