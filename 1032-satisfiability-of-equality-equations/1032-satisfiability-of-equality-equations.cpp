class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(x==parent[x])
        return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y)
    {
        int xp=find(x);
        int yp=find(y);

        if(xp==yp)
        return;

        if(rank[xp]>rank[yp])
        parent[yp]=xp;
        else if(rank[xp]<rank[yp])
        parent[xp]=yp;
        else{
        parent[xp]=yp;
        rank[yp]++;
        }

    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26,0);
        rank.resize(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(auto&s:equations)
        {
            if(s[1]=='=')
            {
            Union(s[0]-'a',s[3]-'a');
            }
        }

        for(auto&s:equations)
        {
            if(s[1]=='!')
            {
                char a=s[0];
                char b=s[3];

                int pa=find(a-'a');
                int pb=find(b-'a');

                if(pa==pb)
                return false;
            }
        }
        return true;
    }
};