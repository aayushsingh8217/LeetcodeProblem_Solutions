class Solution {
public:
    int findCircleNum(vector<vector<int>>& isC) {
        int n=isC.size();
        int flag=0;
        unordered_map<int,vector<int>> mp;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isC[i][j]==1)
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
            // solvedfs(mp,vis,i);
            solvebfs(mp,vis,i);
            flag++; 
            }
        }

        return flag;

      

    }

    // void solvedfs(unordered_map<int,vector<int>>& mp,vector<bool>& vis,int u)
    // {
    //     vis[u]=true;

    //     for(auto &v:mp[u])
    //     {
    //         if(vis[v]==false )
    //         solvedfs(mp,vis,v);

            
    //     }

        
    // }
void solvebfs(unordered_map<int,vector<int>>& mp,vector<bool>& vis,int u)
     {
        queue <int> q;

        q.push(u);

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            for(auto& v:mp[curr])
            {
                if (!vis[v]) { // If neighbor hasn't been visited yet
                    vis[v] = true; // Mark as visited
                    q.push(v); 
            }
        }
     }
     }
    
};