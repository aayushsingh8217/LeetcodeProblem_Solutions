class Solution {
public:
vector<vector<int>> direc{{1,1},{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        auto isValid=[&](int x,int y)
        {
            if(x>=0 && y>=0 && x<m && y<n)
            return true;

            return false;
        };

        queue <pair<int,int>> q;

        if(m==0 || n==0 || grid[0][0]!=0)
        return -1;

        q.push({0,0});
        grid[0][0]=1;

        int level=0;

        while(!q.empty())
        {
            int l=q.size();

            while(l--)
            {
                auto curr=q.front();
                q.pop();

                int x=curr.first;
                int y=curr.second;

                if(x==m-1 && y==n-1)
                return level+1;
                

                for(auto dir:direc)
                {
                    int x_=x+dir[0];
                    int y_=y+dir[1];

                    if(isValid(x_,y_) && grid[x_][y_]==0)
                    {
                        q.push({x_,y_});
                        grid[x_][y_]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};