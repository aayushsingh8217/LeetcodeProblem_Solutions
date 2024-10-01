class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> indg(V,0);
       for (const auto& pre : prerequisites) {
            int course = pre[0];  // Course that has a prerequisite
            int prerequisite = pre[1];  // Prerequisite course
            mp[prerequisite].push_back(course);  // There is an edge from prerequisite to course
            indg[course]++;  // Increment the in-degree of the course
        }

        

        return toposort(mp,indg,V);

    }

    bool toposort( unordered_map<int,vector<int>>& mp, vector<int>& indg,int n)
    {
        queue <int> q;
        int flag=0;

        for(int i=0;i<n;i++)
        {
            if(indg[i]==0)
            {
                q.push(i);
                flag++;
            }
        }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto & v: mp[u])
            {
                indg[v]--;

                if(indg[v]==0)
                {
                    flag++;
                    q.push(v);
                }
            }
        }

        if(flag==n)
        return true;
        else
        return false;
    }
};