class Solution {
public:
bool hc;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> vis(numCourses,false);
        vector<int> inr(numCourses,false);
        stack <int> st;
        for(auto& v:prerequisites)
        {
            int a=v[0];
            int b=v[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            solvedfs(adj,i,vis,inr,st);
        }

        if(hc==true)
        return {};

        vector<int> res;

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;

    }
    void solvedfs(unordered_map<int,vector<int>>& adj,int u,vector<int>& vis,vector<int>& inr,stack <int> & st)
    {
        vis[u]=true;
        inr[u]=true;

        for(auto &v:adj[u])
        {
            if(inr[v]==true)
            {
                hc=true;
                return;
            }
            if(!vis[v])
            solvedfs(adj,v,vis,inr,st);
        }
        st.push(u);
        inr[u]=false;
    }
};