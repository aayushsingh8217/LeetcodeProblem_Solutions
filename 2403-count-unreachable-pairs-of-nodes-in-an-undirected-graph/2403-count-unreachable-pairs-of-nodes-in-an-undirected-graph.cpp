class Solution {
public:
vector<int> parent;
vector<int> rank;
int find(int x)
{
    if(parent[x]==x)
    return x;
    return parent[x]=find(parent[x]);
}
void Union(int x,int y)
{
    int xp=find(x);
    int yp=find(y);

    if(xp==yp)
    return ;

    if(rank[xp]>rank[yp])
    parent[yp]=xp;
    else if(rank[xp]<rank[yp])
    parent[xp]=yp;
    else
    {
        parent[xp]=yp;
        rank[yp]++;
    }
}


    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n,0);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        for (auto& vec:edges)
        {
            int u=vec[0];
            int v=vec[1];

            Union(u,v);
        }

        //step 2 complete

        //step 3 papa
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            int papa=find(i);
            mp[papa]++;
        }

        long long res=0;
        long long remN=n;

        for(auto&it:mp)
        {
            long long size=it.second;
            res+=size*(remN-size);
            remN=remN-size;

        }
        return res;
    }
};