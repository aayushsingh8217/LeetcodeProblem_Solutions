class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector <bool> vis(numCourses,false);
        vector<bool> inr(numCourses,false);

        for(auto& it:prerequisites)
        {
            int a =it[0];
            int b=it[1];
            adj[b].push_back(a);

        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i] && solvedfs(adj,i,vis,inr))
            return false;
        }
        return true;
    }
    bool solvedfs(unordered_map<int,vector<int>> &adj,int u, vector <bool> &vis, vector <bool> &inr)
    {
        vis[u]=true;
        inr[u]=true;

        for(auto &v:adj[u])
        {
            if(!vis[v] && solvedfs(adj,v,vis,inr))
            return true;
            else if(inr[v]==true)
            return true;
        }
        inr[u]=false;
        return false;
    }
};