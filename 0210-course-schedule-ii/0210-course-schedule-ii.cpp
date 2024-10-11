class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> indg(numCourses,0);

        for(auto & it:prerequisites )
        {
            int a=it[0];
            int b=it[1];

            mp[b].push_back(a);
            indg[a]++;

        }

        return toposort(mp,indg,numCourses);

    }

    vector<int> toposort(unordered_map<int,vector<int>>& mp,vector<int>& indg,int n)
    {
        queue <int> q;
        vector<int> res;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(indg[i]==0)
            {
                res.push_back(i);
                q.push(i);
                flag++;

            }
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto &v:mp[u])
            {
                indg[v]--;
                if(indg[v]==0)
                {
                    res.push_back(v);
                    flag++;
                    q.push(v);
                }
            }
        }
        if(flag==n)
        return res;
        else 
        return {};
    }
};