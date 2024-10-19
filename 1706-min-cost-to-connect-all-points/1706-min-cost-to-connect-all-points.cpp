class Solution {
public:
typedef pair<int,int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<p>> adj(V);

        for(int i=0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int wt=abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<bool> inMST(V, false);

        pq.push({0,0});
        int sum=0;

        while(!pq.empty())
        {
            auto n=pq.top();
            pq.pop();

            int wt=n.first;
            int node=n.second;

            if(inMST[node]==true)
            continue;

            inMST[node]=true;
            sum+=wt;

            for(auto &vec:adj[node])
            {
                int neigh=vec.first;
                int neigh_wt=vec.second;

                if(inMST[neigh]==false)
                pq.push({neigh_wt,neigh});
            }
        }
        return sum;

    }
};