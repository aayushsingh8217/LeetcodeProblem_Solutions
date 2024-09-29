class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        //BFS
        int currc=image[sr][sc];
        queue <pair<int,int>> q;
        q.push({sr,sc});
        set <pair<int,int>> vis;
        //vis.insert({sr,sc});
        vector<vector<int>> neigh={{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            image[x][y]=color;
            vis.insert({x,y});
            for(auto &it:neigh)
            {
                int dx=it[0],dy=it[1];
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny]==currc && vis.find({nx,ny})==vis.end() )
                    q.push({nx,ny});


                
            }

        }
        return image;

    }
};