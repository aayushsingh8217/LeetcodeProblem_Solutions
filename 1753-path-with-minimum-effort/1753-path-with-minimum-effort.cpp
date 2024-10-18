class Solution {
public:
vector<vector<int>> direc ={{0,1},{1,0},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
      int m=heights.size();
      int n=heights[0].size();

      vector<vector<int>> res(m,vector<int>(n,INT_MAX));
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
      pq.push({0,{0,0}});
      res[0][0]=0;

      auto isValid=[&](int x,int y)
      {
        if(x>=0 && y>=0 && x<m && y<n)
        return true;
        return false;
      };

      while(!pq.empty())
      {
        int d=pq.top().first;
        auto node=pq.top().second;
        pq.pop();
        int x=node.first;
        int y=node.second;

        if(x==m-1 && y==n-1)
        return d; //as min heap toh top par hi hooga element

        for(auto dir:direc)
        {
            int x_=x+dir[0];
            int y_=y+dir[1];

            if(isValid(x_,y_))
            {
                int absdiff=abs(heights[x][y]-heights[x_][y_]);
                int maxdiff=max(d,absdiff);
                if(res[x_][y_]>maxdiff)
                {
                    res[x_][y_]=maxdiff;
                    pq.push({maxdiff,{x_,y_}});
                }
            }
        }
      }
      return res[m-1][n-1]; 
    }
};