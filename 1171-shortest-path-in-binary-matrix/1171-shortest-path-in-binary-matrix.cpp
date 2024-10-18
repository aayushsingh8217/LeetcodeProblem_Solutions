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

        

        if(m==0 || n==0 || grid[0][0]!=0)
        return -1;
        // BFS---------------------------------------
        // queue <pair<int,int>> q;
        // q.push({0,0});
        // grid[0][0]=1;

        // int level=0;

        // while(!q.empty())
        // {
        //     int l=q.size();

        //     while(l--)
        //     {
        //         auto curr=q.front();
        //         q.pop();

        //         int x=curr.first;
        //         int y=curr.second;

        //         if(x==m-1 && y==n-1)
        //         return level+1;
                

        //         for(auto dir:direc)
        //         {
        //             int x_=x+dir[0];
        //             int y_=y+dir[1];

        //             if(isValid(x_,y_) && grid[x_][y_]==0)
        //             {
        //                 q.push({x_,y_});
        //                 grid[x_][y_]=1;
        //             }
        //         }
        //     }
        //     level++;
        // }
        // return -1;



        // DJ__________________________________________________________

        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        res[0][0]=0;


        while(!pq.empty())
        {
            int d=pq.top().first;
            auto node=pq.top().second;
            int x=node.first;
            int y=node.second;

            pq.pop();

            for(auto dir:direc)
            {
                int x_=x+dir[0];
                int y_=y+dir[1];

                int dist=1;

                if(isValid(x_,y_) && grid[x_][y_]==0 && d+dist<res[x_][y_])
                {
                    pq.push({d+dist,{x_,y_}});
                    grid[x_][y_]=1;
                    res[x_][y_]=d+dist;

                }
            }
        }
        if(res[m-1][n-1]==INT_MAX)
        return -1;
        else return 1+res[m-1][n-1];

    }
};