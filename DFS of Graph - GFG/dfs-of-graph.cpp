//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map <int,vector<int>> mp;
        for(int i=0;i<V;i++)
        {
            for(auto it=adj[i].begin();it!=adj[i].end();it++)
            {
                mp[i].push_back(*it);
            }
        }
        vector <int> res;
        vector<bool> vis(V,false);
        DFS(mp,0,vis,res);
        return res;
    }
    void DFS(unordered_map <int,vector<int>> mp,int u,vector<bool>& vis, vector <int>& res)
    {
        if(vis[u]==true)
        return ;
        vis[u]=true;
        res.push_back(u);
        for(int &v:mp[u])
        {
            if(!vis[v])
            DFS(mp,v,vis,res);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends