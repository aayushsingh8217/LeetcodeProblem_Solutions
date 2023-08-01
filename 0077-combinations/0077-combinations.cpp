class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
       vector <vector <int>> res;
        vector <int> curr_comb;
        backtrack(n,k,1,curr_comb,res);
        return res;
    }
  void backtrack(int n,int k,int idx,vector <int> & curr_comb,vector <vector<int>>& res)
  {
      if(curr_comb.size()==k)
      {
          res.push_back(curr_comb);
          return;
      }
      for(int i=idx;i<=n;i++)
      {
          curr_comb.push_back(i);
          backtrack(n,k,i+1,curr_comb,res);
          curr_comb.pop_back();
      }
  }
};